class body{
private:
	static std::vector<body*> index;
	std::vector<body*> children;
	body* parent;
	orbit orb;
public:
	double gm;
	double radius;
	std::string name;
//constructors
	body():
		gm(1),
		radius(0),
		name("generic_planet"),
		orb()
	{
		index.push_back(this);
	};
	body(
		double i_gm,
		double i_radius
	):
		gm(i_gm),
		radius(i_radius),
		name("generic_planet"),
		orb()
	{
		index.push_back(this);
		orb.gm = i_gm;
	};
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
		index.push_back(this);
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
	int addChild(double i_gm,double i_radius){
		body*newChild = new body(i_gm,i_radius,this);
		children.push_back(newChild);
		index.push_back(newChild);
		return 0;
	};
	body* latestChild(){
		return children[children.size()-1];
	};
};

std::vector<body*> body::index;

body parent_NONE; //no parent value
