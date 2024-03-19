#ifndef CONCLUSION_H
#define CONCLUSION_H

#include <QGraphicsView>
#include <QWidget>

namespace Ui
{
class Conclusion;
}

class Conclusion : public QWidget
{
    Q_OBJECT

public:
    explicit Conclusion(QWidget* parent = nullptr);
    ~Conclusion();

public slots:
    void getCon(QString s);

private:
    Ui::Conclusion* ui;
};

#endif // CONCLUSION_H
