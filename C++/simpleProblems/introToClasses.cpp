/*
 * Problem 1:
 * Point3d simple class
 */
#include <iostream>

class Point3d
{
	float m_x, m_y, m_z;
	public:
		void setValues(float a, float b, float c)
		{
			m_x = a;
			m_y = b;
			m_z = c;	
		};
		void print(){
			std::cout << "<" << m_x << "," << m_y << "," << m_z << ">" << std::endl;
		};
		bool isEqual(Point3d &a){
			if ((m_x == a.m_x) && (m_y == a.m_y) && (m_z == a.m_z)){
				return true;
			}
			return false;
		};
};

int main()
{
	Point3d point;
	point.setValues(1.0, 2.0, 3.5);
	point.print();

	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);
	
	if (point.isEqual(point1))
	{
		std::cout << "They are equal" << std::endl;
	}else
	{
		std::cout << "They are not equal" << std::endl;
	}

	return 0;
}

