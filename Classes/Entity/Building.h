#ifndef _Building_H_

{
public:
	CREATE_FUNC(Building);
	virtual bool init();
	void run();
protected:
	double PositionX;        //x����
	double PositionY;        //y����
	int Blood;               //Ѫ��
	double sizeX;            //��С������
	double sizeY;            //��С������
};
#endif