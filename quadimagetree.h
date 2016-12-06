#ifndef QUADIMAGETREE_H
#define QUADIMAGETREE_H

#include <QImage>
#include <QLabel>
#include <QFile>
#include <QtDebug>
#include <iostream>

using namespace std;

struct QuadImageNode {
    QuadImageNode();

    ~QuadImageNode();

    QRgb m_color;

    QuadImageNode *m_children[4];
};

class QuadImageTree
{
public:
    QuadImageTree();

    void loadImage(const QString &fileName);

    void convert2Grayscale();

    void buildQTree(float _threshold=0.0);

    void loadQTree();

    void loadQTreeFromFile();

    void saveQTree();

    void paint(QLabel *_drawer);

    QuadImageNode m_node;

private:
    /*Returns true in case it doesn't trespass the threshold */
    bool isInvariant(int _x0, int _xf, int _y0, int _yf, float _threshold=0.0);

    void buildQTree(QuadImageNode *ptr, int _x0, int _xf, int _y0, int _yf, float _threshold=0.0);

    void QTreeImage(QuadImageNode *ptr, int _x0, int _xf, int _y0, int _yf);

    void QTree2File(QuadImageNode *ptr, QDataStream &out);

    void QTreeFromFile(QuadImageNode *ptr, QDataStream &in);

    QImage m_picture;

    QSize m_size;
};

#endif // QUADIMAGETREE_H
