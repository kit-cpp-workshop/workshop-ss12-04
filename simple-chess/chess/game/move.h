#ifndef MOVE_H
#define MOVE_H

#include "../general.h"
#include "piece.h"
#include "chessboard.h"


namespace chess {
namespace game {

class chessboard;
class piece;

class move_chain {
    public:
        /* Fügt dem Zug einen vorher auszuführenden Zug hinzu.
        Der Zug wird hinten angehängt, wenn nicht anders angegeben. */
        void Append(move_chain* move_object, bool last = true);

        /* Wendet diesen Zug schließlich an. Wendet ggf. den vorher auszuführenden Zug an.
        Mit der Angabe des konkreten Spielfeld-Arrays werden die Züge darauf ausgeführt. */
        virtual void Apply(piece* spielfeld[chessboard_size][chessboard_size]) = 0;

        /* Destruktor löscht das angehängte Element (dessen Destruktor löscht das weitere usw ... */
        virtual ~move_chain();
    protected:
        move_chain* PreviousMove;

};


class move : public move_chain {
    public:
        /* Konstruktor, erzeugt einen Zug von `from` nach `to`.*/
        move(coor from, coor to, color player);

        /* Überprüft den Zug, ob Start- und Endfeld auf dem Spielfeld möglich sind
        und ob es sich um einen besonderen Zug handelt.
        Prüft, ob Figurenregeln zutreffen.
        Beim Schlagen oder bei besonderen Zügen (z.B. Rochade) werden
        die zusätzlichen Züge (Figur vom Spielfeld nehmen usw... ) dem Zug hinzugefügt,
        sodass schließlich alle Informationen des Zuges enthalten sind.
        Da über die `chessboard`-Klasse nur abfragen möglich sind, ist noch keine Manipulation möglich. */
        bool CheckMove(chessboard &spielfeld);

        void Apply(piece* spielfeld[chessboard_size][chessboard_size]);
    protected:
        coor source, dest;
        color playercolor;
};

class remove : public move_chain {
    public:
        /* Konstruktor, löscht eine Figur auf `field` vom dem Spielfeld.*/
        remove(coor field);
        void Apply(piece* spielfeld[chessboard_size][chessboard_size]);
    private:
        coor chessfield;

};

class insert : public move_chain {
    public:
        /* Konstruktor, fügt eine Figur auf `field` ins Spielfeld ein. */
        insert(coor field, piece &figur);
        void Apply(piece* spielfeld[chessboard_size][chessboard_size]);
    private:
        coor chessfield;
        piece* chessfigure;
};

}
}

#endif // MOVE_H
