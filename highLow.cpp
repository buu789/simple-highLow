#include <iostream>
#include "random.h"

bool playAgain(){

    while(true){
        char c{};
        std::cout<<"Would you like to continue playing (y/n) ? ";
        std::cin>>c;

        if(c=='y')
        return true;
        else if(c=='n'){
            std::cout<<"Thank you for playing.\n";
            return false;
        }
        else continue;
    }

}

void game(int min, int max, int n){

    std::cout<<"Let's play a game. I'm thinking of a number between 1 and 100. You have "<<n<<" tries to guess what it is.\n";

    int num{Random::get(min,max)};

    for(int i{1};i<=n;++i){
        std::cout<<"Guess #"<<i<<": ";

        int x{};
        std::cin>>x;

        if(x>num){
            std::cout<<"Your guess is too high.\n";
        }
        else if(x<num){
            std::cout<<"Your guess is too low.\n";
        }
        else{
            std::cout<<"Hurray!!! You win!\n";
            return;
        }
    }

    std::cout<<"Sorry, you lose. The correct answer was "<<num<<'\n';
    return;
}

int main(){

    int min{1};
    int max{100};
    int noGuess{7};

    do{
        game(min,max,noGuess);
    }while(playAgain());

    return 0;
}
