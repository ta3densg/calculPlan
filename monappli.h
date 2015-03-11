#ifndef MONAPPLI_H
#define MONAPPLI_H
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
//#include <plan.h>

using namespace std;

class MonAppli : public QWidget
{
private:
    QPushButton *monBouton;
    int posx;
    int posy;
    int c1=0;
    double ABx;
    double ABy;
    double ABz;
    double ACx;
    double ACy;
    double ACz;
    int hp=100000;
    vector<int> tableauX;
    vector<int> tableauY;
    //Plan plans;


public:
    MonAppli(QWidget *parent= 0) : QWidget(parent)
    {
        monBouton = new QPushButton(tr("Quitter"));
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(monBouton);
        setLayout(layout);

        connect( monBouton, SIGNAL(clicked()), this, SLOT(close()));

        // connecte le signal pressed du bouton à une method de l'appli
        this->connect(monBouton, SIGNAL(pressed()), SLOT(boutonPressed()));

    }

    ~MonAppli()
    {
        delete monBouton;
    }

public slots:

    void mousePressEvent(QMouseEvent * ev);
    void boutonPressed(void);
    void affichage();
    void stockValeur();
    void calculPlan();

private:


};

#endif // MONAPPLI_H
