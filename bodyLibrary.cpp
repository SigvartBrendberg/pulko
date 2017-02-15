#include "body.hpp"

body sun(1.32712440018e20,695700000);
body earth(3.986004418e14,6371000,&sun);
body moon(4.9048695e12,1737100,&earth);

body parent_NONE; //no parent value
