#include <ctime>
#include <iostream>
struct Snake
{
	int x, y;
};
class snake {
public:
	snake(int x5,int y5,int x4,int y4,int x3,int y3,int x2,int y2,int x1,int y1,int x0,int y0) {  //���캯��
		length = 6;
		s[5].x = x5;
		s[5].y = y5;
		s[4].x = x4;
		s[4].y = y4;
		s[3].x = x3;
		s[3].y = y3;
		s[2].x = x2;
		s[2].y = y2;
		s[1].x = x1;
		s[1].y = y1;
		s[0].x = x0;
		s[0].y = y0;
		up = left = down = 0;
		right = 1;
	}
	~snake(){}
	void display();                                    //��ʾ��
	void Rightmove();                                  //���������ƶ���
	void Leftmove();
	void Upmove();
	void Downmove();
	void showhead();
	int preCheakRightmove();
	int preCheakLeftmove();
	int preCheakUpmove();
	int preCheakDownmove();
    std::string getstate();
	int cheak();                                      //����Ƿ�ײ��ǽ��������
	void creat_food();                                //����ʵ��
	int eat_food();                                   //��ʳ��
private:
	struct Snake s[100];                              //�������100
	int length;                                       //��ǰ�ߵĳ���
	int x3, y3;                                       //ʳ������
	int up, down, right, left;                        //�ߵ�״̬

};
void make_frame();                                    //��ӡ��ܵĺ���
void show();                                          //��Ϸ��ʼ����
void gameover();                                      //��Ϸ����
class myRand {
public:
	unsigned int seed;
	void srand(unsigned int s = static_cast<unsigned int> (time(NULL))) {
		seed = s;
	}
	unsigned int rand() {
		seed = (31 * seed + 13) % ((1 << 15) - 1);
		return seed;
	}
};