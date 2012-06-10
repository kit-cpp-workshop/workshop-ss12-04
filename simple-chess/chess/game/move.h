#ifndef MOVE_H
#define MOVE_H

#include "../general.h"
#include "piece.h"
#include "chessboard.h"


namespace chess {
namespace game {

class chessboard;

class move_chain {
    public:
        /* Fügt dem Zug einen vorher auszuführenden Zug hinzu.
        Diesem wird automatisch dasselbe Brett zugewiesen. */
        void Append(move_chain* move_object);

        /* Wendet diesen Zug schließlich an. Wendet ggf. den vorher auszuführenden Zug an.
        Mit der Angabe des konkreten Spielfeld-Arrays werden die Züge darauf ausgeführt. */
        void Apply(piece* spielfeld[chessboard_size][chessboard_size]);

    protected:
        move_chain* PreviousMove;

};


class move : public move_chain {
    public:
        /* Konstruktor, erzeugt einen Zug von `from` nach `to` auf dem Spielfeld.*/
        move(coor from, coor to, color player, chessboard &spielfeld);

        /* Überprüft den Zug, ob Start- und Endfeld möglich sind
        und ob es sich um einen besonderen Zug handelt.
        Prüft, ob Figurenregeln zutreffen.
        Beim Schlagen oder bei besonderen Zügen (z.B. Rochade) werden
        die zusätzlichen Züge (Figur vom Spielfeld nehmen usw... ) dem Zug hinzugefügt,
        sodass schließlich alle Informationen des Zuges enthalten sind.
        Da über die `chessboard`-Klasse nur abfragen möglich sind, ist noch keine Manipulation möglich. */
        bool CheckMove();

    protected:
        coor from, to;
        color player;

};

class remove : public move_chain {
    public:
        /* Konstruktor, löscht eine Figur auf `field` vom dem Spielfeld.*/
        remove(coor field);
    private:
        coor field;

};

class insert : public move_chain {
    public:
        /* Konstruktor, fügt eine Figur auf `field` ins Spielfeld ein. */
        insert(coor field, piece &figur);
    private:
        coor field;

};

}
}

#endif // MOVE_H
