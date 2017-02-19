#include "body.hpp"

void initSystem(body* root){
body* sun = root->addChild(1.32712440018e20,695700000,"sun");
sun->addChild(2.2032e13,2439700,"mercury");
sun->addChild(3.24859e14,6051800,"venus");
body* planet = sun->addChild(3.986004418e14,6371000,"earth");
	planet->addChild(4.9048695e12,1737100,"moon");
planet = sun->addChild(4.282837e13,3389500,"mars");
	planet->addChild("phobos");
	planet->addChild("deimos");
sun->addChild(6.26325e10,473000,"ceres");
sun->addChild("pallas");
sun->addChild("vesta");
sun->addChild("hygiea");
sun->addChild("interamnia");
planet = sun->addChild(1.26686534e17,69911000,"jupiter");
	planet->addChild("io");
	planet->addChild("europa");
	planet->addChild("ganymede");
	planet->addChild("callisto");
planet = sun->addChild(3.7931187e16,58232000,"saturn");
	planet->addChild("titan");
	planet->addChild("rhea");
	planet->addChild("iapetus");
	planet->addChild("tethys");
	planet->addChild("dione");
	planet->addChild("enceladus");
	planet->addChild("mimas");
	planet->addChild("hyperion");
	planet->addChild("phoebe");
planet = sun->addChild(5.793939e15,25362000,"uranus");
	planet->addChild("titania");
	planet->addChild("oberon");
	planet->addChild("umbriel");
	planet->addChild("ariel");
	planet->addChild("miranda");
planet = sun->addChild(6.836529e15,24622,"neptune");
	planet->addChild("triton");
	planet->addChild("proteus");
	planet->addChild("nereid");
planet = sun->addChild(8.71e11,1186000,"pluto");
	planet->addChild("charon");
planet = sun->addChild("varda");
	planet->addChild("ilmare");
planet = sun->addChild(1.108e12,1163000,"eris");
	planet->addChild("dysnomia");
sun->addChild("makemake");
planet = sun->addChild("haumea");
	planet->addChild("hiiaka");
sun->addChild("quaoar");
sun->addChild("225088 2007 OR10");
sun->addChild("307261 2002 MS4");
planet = sun->addChild("orcus");
	planet->addChild("vanth");
sun->addChild("salacia");
sun->addChild("sedna");
};
