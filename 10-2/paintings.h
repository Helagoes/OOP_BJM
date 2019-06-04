class GraphicObject{
public:
	virtual ~GraphicObject() {};
	virtual void paint () = 0;
	virtual bool is_in(int x, int y) const = 0;
};

class Rectangle : public GraphicObject {
public:
	Rectangle(int top, int left, int height, int width);
	void paint() override;
	bool is_in(int x, int y) const override;
protected:
	int top, left, width;
private:
	int height;
};

class Square : public Rectangle { //Jedes Quadrat ist ein Rechteck mit Besonderheit: Höhe == Breite
								  //Muss nur Konstruktor anlegen, alles andere wird entsprechend von Rectangle geerbt, height fällt dabei weg
public:
	Square(int top, int left, int width);
};

class Circle : public GraphicObject{
public:
	Circle(int x, int y, int r);
	void paint() override;
	bool is_in(int x, int y) const override;
protected:
	int center_x, center_y, radius;
};
