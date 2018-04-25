
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Team {
	public:
		Team(string s, unsigned int wins, unsigned int losses);
		bool operator<(const Team &t){
			if(this->wins/(this->wins+this->losses) < t.wins/(t.wins+t.losses)){
				return true;
			}
		}

	private:
		string s;
		unsigned int wins;
		unsigned int losses;
};

Team::Team(string s, unsigned int wins, unsigned int losses){
	this->s = s;
	this->wins = wins;
	this->losses = losses;
}


// Not my code.
template <typename T>
void mergesort(vector<T> &v){
	if(v.size() <= 1){
		return;
	}

	vector<T> left, right;
	int center = (int)(v.size()/2);

	for(int i = 0; i < center; i++){
		left.push_back(v[i]);
	}

	for(int i = center; i < (int)v.size(); i++){
		right.push_back(v[i]);
	}
	
	left = mergesort(left);
	right = mergesort(right);
	v = merge(left, right);
}
// Not my code
template <typename T>
vector<T> merge(vector <T> left, vector<T> right){
	vector<T> result;
	while ((int)left.size() > 0 || (int)right.size() > 0) {
		if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
		}
	}
	return result;
}

int main(){
	vector<Team> vector;
	Team Ace("Ace", 2, 1);
	Team Bear("Bear", 3, 0);
	vector.push_back(Ace);
	vector.push_back(Bear);
	mergesort(vector);
}
