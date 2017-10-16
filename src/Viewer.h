// Viewer.h

#ifndef VIEWER_H

#define VIEWER_H

#include "Transform3.h"
#include <QLabel>

class Viewer: public QLabel {
public:
  Viewer(QWidget *parent=0);
  ~Viewer();
  void setVoxmap(class Voxmap *voxmap);
  void setIDmap(class IDmap *voxmap, int factor);
  virtual void mouseMoveEvent(QMouseEvent *) override;
  virtual void keyPressEvent(QKeyEvent *) override;
  virtual void mousePressEvent(QMouseEvent *) override;
  virtual void mouseReleaseEvent(QMouseEvent *) override;
  virtual void mouseDoubleClickEvent(QMouseEvent *) override;
  virtual void wheelEvent(QWheelEvent *) override;
  virtual void resizeEvent(QResizeEvent *) override;
  virtual void paintEvent(QPaintEvent *) override;
protected:
  void rebuild();
  void rebuildID();
  void ensurePViewer();
  void gotoID(int id);
  void setViewMode();
  void buildLUT();
  QString axlabel(QString ax);
  void showPos(Point3 p); // data coords
  void showPos(QPoint p); // screen coords
  void drawAxis(QString ax, QColor c, Point3 v);
private:
  Transform3 t;
  int hidpi_;
  Voxmap *voxmap;
  IDmap *idmap;
  int idfactor;
  static constexpr int HALFNZ = 5;
  uint32_t lut[(HALFNZ*2+1)*256];
  QPoint dragbase;
  Transform3 t0;
  Transform3 tid;
  Qt::MouseButton dragbutton;
  Qt::KeyboardModifiers dragmods;
  QImage im0;
  uint16_t paintid;
  static constexpr uint16_t DELETEID = 65535;
  static constexpr uint16_t VIEWID = 0;
  bool showids;
  class PViewer *pviewer;
  QString lastkey;
  QLabel *message;
  QLabel *message2;
};

#endif
