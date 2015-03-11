
#include <QString>
#include "monappli.h"
#include <QApplication>

using namespace std;


/*
class MonAppli : public QWidget
{
    QMessageBox* msgBox;
private:
    QPushButton *monBouton;
    int posx;
    int posy;
    int c=0;
    vector<int> tableauX;
    vector<int> tableauY;

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

    void mousePressEvent(QMouseEvent * ev)
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

    }

    void boutonPressed(void)
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
    void affichage()
    {
        std::cout<<"Position locale :(" << posx << "," << posy << ")\n";
    }

    void stockValeur()
    {
        c+=1;
        tableauX.push_back(posx);
        tableauY.push_back(posy);
        /*
        int i;
        for (i = 0 ; i < c-1 ; i++)
        {
            printf("%d ", tableauX[i]);
            printf("%d ", tableauY[i]);
        }
    }
    void calculPlan()
    {

    }
};
*/

int main(int argc, char **argv)
{
QApplication app(argc, argv);
    MonAppli *window = new MonAppli();
        window->setWindowTitle(QString::fromUtf8("Mon curseur"));
        window->resize(300, 250);

    window->show();
    return app.exec();
}
