#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<Windows.h>
// ����ȫ�ֱ���
int rosesize = 500;
int h = -250;

// ����ṹ��
struct DOT
{
    double x;
    double y;
    double z;
    double r; // ��ɫ
    double g; // ��ɫ��ע�������޸�Ϊ��ȷ������
};

// �����
bool calc(double a, double b, double c, DOT& dot)
{
    double j, n, o, w, z;
    if (c > 60) // ����
    {
        dot.x = sin(a * 7) * (13 + 5 / (0.2 + pow(b * 4, 4))) - sin(b) * 50;
        dot.y = b * rosesize + 50;
        dot.z = 625 + cos(a * 7) * (13 + 5 / (0.2 + pow(b * 4, 4))) + b * 400;
        dot.r = a * 1 - b / 2;
        dot.g = a;
        return true;
    }

    double A = a * 2 - 1;
    double B = b * 2 - 1;

    if (A * A + B * B < 1)
    {
        if (c > 37)
        {
            j = (int(c) & 1);
            n = j ? 6 : 4;
            o = 0.5 / (a + 0.01) + cos(b * 125) * 3 - a * 300;
            w = b * h;
            dot.x = o * cos(n) + w * sin(n) + j * 610 - 390;
            dot.y = o * sin(n) - w * cos(n) + 550 - j * 350;
            dot.z = 1180 + cos(B + A) * 99 - j * 300;
            dot.r = 0.4 - a * 0.1 + pow(1 - B * B, -h * 6) * 0.15 - a * b * 0.4 + cos(a + b) / 5 + pow(cos((o * (a + 1) + (B > 0 ? w : -w)) / 25), 30) * 0.1 * (1 - B * B);
            dot.g = o / 1000 + 0.7 - o * w * 0.000003;
            return true;
        }
        if (c > 32)
        {
            c = c * 1.16 - 0.15;
            o = a * 45 - 20;
            w = b * b * h;
            z = o * sin(c) + w * cos(c) + 620;
            dot.x = o * cos(c) - w * sin(c);
            dot.y = 28 + cos(B * 0.5) * 99 - b * b * b * 60 - z / 2 - h;
            dot.z = z;
            dot.r = (b * b * 0.3 + pow((1 - (A * A)), 7) * 0.15 + 0.3) * b;
            dot.g = b * 0.7;
            return true;
        }

        o = A * (2 - b) * (80 - c * 2);
        w = 99 - cos(A) * 120 - cos(b) * (-h - c * 4.9) + cos(pow(1 - b, 7)) * 50 + c * 2;
        z = o * sin(c) + w * cos(c) + 700;
        dot.x = o * cos(c) - w * sin(c);
        dot.y = B * 99 - cos(pow(b, 7)) * 50 - c / 3 - z / 1.35 + 450;
        dot.z = z;
        dot.r = (1 - b / 1.2) * 0.9 + a * 0.1;
        dot.g = pow((1 - b), 20) / 4 + 0.05;
        return true;
    }
    return false;
}

// ������
int main()
{
    // �������
    short* zBuffer;
    int x, y, z, zBufferIndex;
    DOT dot;

    // ��ʼ��
    initgraph(640, 480); // ������ͼ����
    setbkcolor(LIGHTBLUE); // ���ñ���ɫΪ����ɫ
    cleardevice(); // ����
    setcolor(RED);
    setbkmode(TRANSPARENT);

    // ��ʼ��
    initgraph(640, 480); // ������ͼ����
    setbkcolor(LIGHTBLUE); // ���ñ���ɫΪ����ɫ
    cleardevice(); // ����
    setcolor(RED);
    setbkmode(TRANSPARENT);
    // ��ȡ�豸�������
    HDC hdc = GetImageHDC();  // ����ʹ�� GetImageHDC ��ȡ�豸�������
    // ��ʼ�� z-buffer
    zBuffer = new short[rosesize * rosesize];
    memset(zBuffer, 0, sizeof(short) * rosesize * rosesize);

    // ��������ʹ�С
    LOGFONT lf;
    ZeroMemory(&lf, sizeof(LOGFONT));
    lf.lfHeight = 20; // �����С
    lf.lfWeight = FW_NORMAL; // �����ϸ
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lf.lfQuality = DEFAULT_QUALITY;
    lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
    lstrcpy(lf.lfFaceName, L"����");

    HFONT hFont = CreateFontIndirect(&lf);
    SelectObject(hdc, hFont);

    // �����ı���ɫ
    SetTextColor(hdc, RGB(255, 0, 0));

    // �����ı�
    TextOut(hdc, 450, 430, L"", 0); // ��һ�еĿ��ַ���
    TextOut(hdc, 500, 450, L"0", 10); // �ڶ��е��ı�
    for (int j = 0; j < 2000 && !_kbhit(); j++) // ��������˳�
    {
        for (int i = 0; i < 10000; i++) // �����Ƿ��а������ж�
        {
            if (calc(double(rand()) / RAND_MAX, double(rand()) / RAND_MAX, rand() % 46 / 0.74, dot))
            {
                z = int(dot.z + 0.5);
                x = int(dot.x * rosesize / z - h + 0.5);
                y = int(dot.y * rosesize / z - h + 0.5);
                if (y >= rosesize)
                    continue;
                zBufferIndex = y * rosesize + x;
                if (!zBuffer[zBufferIndex] || zBuffer[zBufferIndex] > z)
                {
                    zBuffer[zBufferIndex] = z;
                    // ����
                    int r = int(dot.r * h); if (r < 0) r = 0; if (r > 255) r = 255;
                    int g = int(dot.g * h); if (g < 0) g = 0; if (g > 255) g = 255;
                    int b = int(dot.r * dot.r * -80); if (b < 0) b = 0; if (b > 255) b = 255;
                    putpixel(x + 50, y - 20, RGB(r, g, b));
                }
            }
        }
        Sleep(5);
    }

    // �˳�
    delete[] zBuffer;
    _getch();
    closegraph();
    return 0;
}
