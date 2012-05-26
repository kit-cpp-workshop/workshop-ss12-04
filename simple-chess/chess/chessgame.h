#ifndef CHESSGAME_H
#define CHESSGAME_H


namespace chess{

class chessgame
{
    public:
        chessgame();
        ~chessgame();
        void run(); // hier drin steckt der Spielablauf: Abwechselnd weiß und schwarz ziehen, bis König geschlagen.
    protected:
    private:
        bool current_player_color;
};


}
#endif // CHESSGAME_H
