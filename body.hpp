#ifndef INC_body_HPP
#define INC_body_HPP

#include <vector>
#include <string>

#include "state.hpp"
#include "atmosphere.hpp"

class body{
private:
	std::vector<body> children;
	std::vector<body*> dynamicChildren;
	body* parent;
public:
	double gm;
	double radius;
	std::string name;
	bool hasAtmosphere;
	atmosphere air;
	orbit orb;
//constructors
	body():
		gm(1),
		radius(0),
		name("generic_planet"),
		orb()
	{
		orb.gm = 1;
	};
//
	body(
		body*i_parent
	):
		parent(i_parent),
		name("generic_planet"),
		orb()
	{
		i_parent->addChild(this);
	};
//
	body(
		double i_gm,
		double i_radius
	):
		gm(i_gm),
		radius(i_radius),
		name("generic_planet"),
		orb()
	{
		orb.gm = i_gm;
	};
//
	body(
		double i_gm,
		double i_radius,
		body*i_parent
	):
		parent(i_parent),
		gm(i_gm),
		radius(i_radius),
		name("generic_planet"),
		orb()
	{
		i_parent->addChild(this);
		orb.gm = i_gm;
	};
//
	body(
		body*i_parent,
		std::string i_name
	):
		parent(i_parent),
		name(i_name),
		orb()
	{
		i_parent->addChild(this);
	};
//
	body(
		double i_gm,
		double i_radius,
		body*i_parent,
		std::string i_name
	):
		parent(i_parent),
		gm(i_gm),
		radius(i_radius),
		name(i_name),
		orb()
	{
		i_parent->addChild(this);
		orb.gm = i_gm;
	};
	body(
		double i_gm,
		double i_radius,
		std::string i_name
	):
		gm(i_gm),
		radius(i_radius),
		name(i_name),
		orb()
	{
		orb.gm = i_gm;
	};
	body(
		std::string i_name
	):
		name(i_name),
		orb()
	{};
//destructors
	~body(){};
//info
	body* getParent(){
		return parent;
	};
	double gravity(double altitude){
		return gm/((radius + altitude)*(radius + altitude));
	};
//actions
	void addChild(body*newChild){
		dynamicChildren.push_back(newChild);
	};
	body* addChild(
		double gm,
		double radius,
		std::string name
	){
		body newChild(gm,radius,name);
		children.push_back(newChild);
		return &children[children.size()-1];
	};
	body* addChild(
		std::string name
	){
		body newChild(name);
		children.push_back(newChild);
		return &children[children.size()-1];
	};
	body* latestChild(){
		return &children[children.size()-1];
	};
};

#endif
