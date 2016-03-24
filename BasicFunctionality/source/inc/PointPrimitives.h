﻿#ifndef __POINT_PRIMITIVES_H__
#define __POINT_PRIMITIVES_H__

#include <osg/Geometry>

#include "IPointPrimitives.h"


// <绘制电元的实现类，继承于IPointPrimitives>
class PointPrimitives :public IPointPrimitives
{
public:
	
	// <构造函数，用于初始化私有变量>
	PointPrimitives();

	// <获取点的位置>
	virtual void getPosition(float& x, float& y, float& z) const override;
	
	// <设置点的位置>
	virtual void setPosition(float x, float y, float z) override;
	
	// <获取的大小尺寸>
	virtual float getSize() const override;
	
	// <设置点的大小尺寸>
	virtual void setSize(float size) override;
	// <设置点的颜色，三个浮点值参数分别表示红、绿、蓝，透明度默认为1.0f>
	virtual void setColor(float red, float green, float blue) override;
	
	// <获取点的位置，返回成VertexArray类型>
	virtual VertexArray getVertices() const override;
	
	// <设置点的坐标，用VertexArray的类型>
	virtual void setVertices(const VertexArray& arr) override;

// internal:
	osg::Geometry *getGeometry();

	virtual osg::Vec3 getPosition() const;

	virtual void setPosition(osg::Vec3 pos);

private:
	osg::ref_ptr<osg::Geometry> _geometry;
	osg::Vec3 _vertex;
	osg::ref_ptr<osg::Vec4Array> _color;
	osg::ref_ptr<osg::Vec3Array>_vertices;
	float _size;
};



#endif // __POINT_PRIMITIVES_H__