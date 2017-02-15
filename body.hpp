#ifndef INC_body_HPP
#define INC_body_HPP

#include <iostream>
#include <vector>
#include <string>

#include "state.hpp"
#include "atmosphere.hpp"

class body{
private:
	std::vector<body*> children;
	body* parent;
	orbit orb;
public:
	double gm;
	double radius;
	std::string name;
	bool hasAtmosphere;
	atmosphere air;
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
		gm(i_gm),
		radius(i_radius),
		parent(i_parent),
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
		gm(i_gm),
		radius(i_radius),
		parent(i_parent),
		name(i_name),
		orb()
	{
		i_parent->addChild(this);
		orb.gm = i_gm;
	};
//destructors
	~body(){
		std::cout << name << " crunched" << std::endl;
		for(unsigned int i = 0; i < children.size();i++){
			delete children[i];
		};
	};
//info
	body* getParent(){
		return parent;
	};
//actions
	int addChild(body* newChild){
		children.push_back(newChild);
		return 0;
	};
	body* latestChild(){
		return children[children.size()-1];
	};
};

body* init_solarSystem();

#endif
