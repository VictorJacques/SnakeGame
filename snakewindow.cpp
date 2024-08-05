#include "snakewindow.h"

SnakeWindow::SnakeWindow(QWidget *parent)
    : QWidget(parent)
{
    _scene = new QGraphicsScene();
    _scene->setBackgroundBrush(Qt::white);
    //_scene->setSceneRect(-300,-300,600,600);

    QGraphicsLineItem * x_axis = _scene->addLine(-400, -20, 400, -20);
    x_axis->setZValue(10);
    QGraphicsLineItem * x_axis2 = _scene->addLine(-400, 20, 400, 20);
    x_axis2->setZValue(10);
    QGraphicsLineItem * y_axis = _scene->addLine(-20, -400, -20, 400);
    y_axis->setZValue(10);
    QGraphicsLineItem * y_axis2 = _scene->addLine(20, -400, 20, 400);
    y_axis->setZValue(10);
    QGraphicsTextItem * minus_x = _scene->addText("-300");
    minus_x->setZValue(10);
    minus_x->setPos(QPointF(-300,0));
    QGraphicsTextItem * more_x = _scene->addText("300");
    more_x->setZValue(10);
    more_x->setPos(QPointF(250,0));

    //QGraphicsEllipseItem *ball = _scene->addEllipse(QRectF(-50, -50, 100, 100));
    //ball->setBrush(Qt::blue);
    _ball = new Ball(-10,-10,20,20);
    _ball->setBrush(Qt::green);
    _scene->addItem(_ball);
    QPen mPen;
    mPen.setBrush(Qt::darkYellow);
    mPen.setWidth(2);
    _ball->setPen(mPen);

    _ball->setScale(2);

    _ball->setFlag(QGraphicsItem::ItemIsMovable);
    _ball->setFlag(QGraphicsItem::ItemIsFocusable);


    this->width();
    this->height();

    QGraphicsRectItem * rect = new QGraphicsRectItem(-400,-400,800,800);
    _scene->addItem(rect);



    _view = new QGraphicsView();
    _view->setScene(_scene);

    _layout = new QVBoxLayout();
    _layout->addWidget(_view);
    this->setLayout(_layout);
    setFixedSize(sizeHint());
    setWindowTitle("Jogo da Cobrinha");

    _timer = new QTimer;
    QObject::connect(_timer, SIGNAL(timeout()), _scene, SLOT(advance()));
    _timer->start(1000 / 24);
}

SnakeWindow::~SnakeWindow() {}
