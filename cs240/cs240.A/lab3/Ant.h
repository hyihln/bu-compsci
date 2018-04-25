
class Ant{
	private:
		int id;
		int x;
		int y;
	public:
		Ant(int);
		void move();
		int getID(){
			return id;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		~Ant();
		
};

