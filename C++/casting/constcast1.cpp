#include<iostream>
using namespace std;

class Game
{

   public:
  
   string game_type;

   void select()

   {

	cout <<" Its a  " << game_type << " Game " << endl;
   }
   
    void update(string var) const

    {

        const_cast<Game *>(this)->game_type = var;
        cout<< " Its a "<< var<< " Game "<< endl;

    }


   void update(string var)

    {
     
        this->game_type = var;
	cout<< " Its a "<< var<< " Game "<< endl;

    }


   void select() const
 
   {
        cout<<" Constant function executed"<< endl;
	cout<<"Its a : " << game_type << endl;
   }

  Game(string def):game_type(def){}

};


int main()

{

  Game g1("Baseketball");

  g1.select();
  g1.update("Chess");
  
  const Game g2("Baseball");// When we are using const object its a read only memory i.e we cannot modify the data using g2 variable ame
  
   Game * ptr = const_cast<Game *>(&g2);

   g2.select();

   ptr->update("Carrom");
    
    g2.select();   

  return 0;
}



