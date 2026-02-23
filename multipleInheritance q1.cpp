#include<iostream>
using namespace std;
class shape{
	protected:
		int no_of_sides;
		float area;
		
		public:
			
		shape(int s = 0 ,  float a = 0.0)
		{
			no_of_sides = s;
			area = a;
		}
		
		void setno_of_sides(int sides)
		{
			no_of_sides = sides;
		}
		
		void setarea(float a)
		{
			area = a;
		}
		
		int getsides()
		{
			return no_of_sides;
			
		}
		
		float getarea()
		{
			return area;
		}
	};
		
		class rectangle : public shape{
			protected:
				float length , width;
				
				public:
					rectangle(float l , float w) : shape(4,0)
					{
						length = l;
						width = w;
						generateArea();
					}
					
					void generateArea()
					{
						area = length * width;
					}
								
		};
		
		
		class circle : public shape{
			protected:
				float radius;
				
				public:
					circle(float r)  :shape(0 , 0)
					{
						radius = r;
						generateArea();
					}
					
				void generateArea()
				{
					area = 3.140 * radius * radius;
				}
				
		};
		
		class triangle : public shape{
			protected:
				float height , base;
				
				public:
					
					triangle(float h , float b) : shape(3 , 0)
				    {
				    	height = h;
				    	base = b;
				    	generateArea();
					}
					
					void generateArea()
					{
						area =  height * (base / 2);
					}		
		};
		
		class square : public rectangle{
			public:
				square(int side) : rectangle(side , side){
					no_of_sides = 4;
				}
				
				bool checksides()
				{
					return length == width;
				}
				
				void generateArea()
				{
					area = length * length;
				}
				
		};
int main()
{
    rectangle r(5, 10);
    cout << "Rectangle area: " << r.getarea() << endl;

    circle c(7);
    cout << "Circle area: " << c.getarea() << endl;

    triangle t(6, 8);
    cout << "Triangle area: " << t.getarea() << endl;

    square s(4);
    cout << "Square area: " << s.getarea() << endl;
    
    cout << "Square sides equal? ";

if (s.checksides()) {
    cout << "Yes";
} else {
    cout << "No";
}
}
