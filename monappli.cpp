#include <vector>
#include <iostream>
#include <QCoreApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextStream>
#include <QCursor>
#include <QMouseEvent>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include "monappli.h"
//#include "plan.h"

using namespace std;

void MonAppli::mousePressEvent(QMouseEvent * ev)
{
    QTextStream cout(stdout);

    //Renvoie les coordonnées par rapport au haut gauche de la fenétre locale
    //cout <<"Position locale :(" << ev->x() << "," << ev->y() << ")\n";
    //Revoie les coordonnées par rappourt au haut droit de l'écran
    //cout <<"Position globale :" << ev->globalX() << "," << ev->globalY() << ")\n";
    posx = ev->x();
    posy = ev->y();
    //cout <<"Position locale :(" << pointx << "," << pointy << ")\n";
    affichage();
    stockValeur();
    if (c1%2==0)
        calculPlan();

}

void MonAppli::boutonPressed(void)
{
    // récupère la position de la souris
    QPoint cursorPos = QCursor::pos();

    // créé un évènement, et envoie le à ton appli
    this->mousePressEvent(new QMouseEvent(QEvent::MouseButtonPress,
              cursorPos,
              Qt::LeftButton,
              Qt::LeftButton,
              Qt::NoModifier));
}
void MonAppli::affichage()
{
    std::cout<<"Position locale :(" << posx << "," << posy << ")\n";
}

void MonAppli::stockValeur()
{
    c1+=1;
    tableauX.push_back(posx);
    tableauY.push_back(posy);
    /*
    int i;
    for (i = 0 ; i < c-1 ; i++)
    {
        printf("%d ", tableauX[i]);
        printf("%d ", tableauY[i]);
    }
    */
}

void MonAppli::calculPlan()
{
    ABx=tableauX[c1-1]-tableauX[c1];//ABx
    ABy=tableauY[c1-1]-tableauY[c1];//ABy
    ABz=0;

    ACx = 0;
    ACy = 0;
    ACz = hp;
    vector<int> n(4);
     n[0] = ABy*ABz-ABz*ACy;
     n[1] = ABz*ACx-ABx*ACz;
     n[2] = ABx*ACy-ABy*ACx;
     n[3] = -tableauX[c1]*n[0]-tableauY[c1]*n[1]-n[2]*ABz;


    cout<<"Le plan a pour equation: "<< n[0] <<"x +"<< n[1] <<"y +"<< n[2] <<"z +"<< n[3]<<"\n";
    //cout<<c1<<"\n";

    cout<<c1;
    //delete a,b,c,d;



}
