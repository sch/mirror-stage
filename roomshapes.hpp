/*
 * hardcoded room shapes
 */
const int SHAPESIZE =10;


/*
 * I use shapesize+1 to duplicate the initial vertex; it makes some
 * calculations when drawing the room edges and moving between rooms a little
 * easier.
 */
struct Shape {
  int points[SHAPESIZE+1][2];
};


const int S_SQUARE    = 0;
const int S_TRIANGLE  = 1;
const int S_HEXAGON   = 2;
const int S_ISOSCELES = 3;
const int S_RECTANGLE = 4;
const int S_PENTAGON  = 5;
const int S_TRAPESIUM = 6;
//perturbed shapes next
const int P_SQUARE    = 7;
const int P_TRIANGLE  = 8;
const int P_HEXAGON   = 9;
const int P_ISOSCELES = 10;
const int P_RECTANGLE = 11;
const int P_PENTAGON  = 12;
const int P_TRAPESIUM = 13;
//one side twice length of other
const int S_TRAPESIUM2 = 14;
const int S_REGHEXAGON = 15;
const int R_1          = 16;
const int R_2          = 17;
const int S_TRIANGLE2  = 18;
const int P_TRIANGLE2  = 19;
const int S_RECTOCT    = 20;
const int S_PENROSE1   = 21;
const int S_PENROSE2   = 22;
const int S_BISQUARE   = 23;
const int S_2x1RECT    = 24;
const int S_GLORYHOLE  = 25;
const int S_KOCH1      = 26;
const int S_KOCH2      = 27;
const int S_SEPT       = 28;
const int S_ROCT       = 29;
const int S_NON        = 30;
const int S_DEC        = 31;

const int SHAPECOUNT = 32;

int shapesize[SHAPECOUNT] = {4,3,6,3,4,5,4,4,3,6,3,4,5,4,4,6,5,6,3,3,8,4,4,6,4,6,9,7,7,8,9,10};  // = number of edges (+1???)
const GLfloat shapes[SHAPECOUNT][SHAPESIZE+1][2] =
{
  {//square
    {0.0f,1.0f},
    {1.0f,0.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {-0.0f,1.0f},
  },
  {//equilateral triangle
    {1.0f,  0.0f},
    {-0.5, -0.866025f},
    {-0.5f, 0.866025f},
    {1.0f, 0.0f}
  },
  {//hexagon
    {-0.5f,0.5f},
    {0.5f,0.5f},
    {1.0f,0.0f},
    {0.5f,-0.5f},
    {-0.5f,-0.5f},
    {-1.0f,0.0f},
    {-0.5f,0.5f}
  },
  {//isoceles triangle
    {2.0f,  0.0f},
    {-0.5, -0.866025f},
    {-0.5f, 0.866025f},
    {2.0f, 0.0f}
  },
  {//rectangle
    {1.0f,4.0f},
    {1.0f,-4.0f},
    {-1.0f,-4.0f},
    {-1.0f,4.0f},
    {1.0f,4.0f},
  },
  {//pentagon
    {1.0f,0.0f},
    {0.3090169942383f, -0.95105651f},
    {-0.809016994f,-0.587785252f},
    {-0.80901699f,0.587785252f},
    {0.30901699f,0.9510565f},
    {1.0f,0.0f}
  },
  {//trapesium
    {0.0f,1.3f},
    {1.3f,0.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {-0.0f,1.3f},
  },

  //perturbed shapes next

  {//square
    {0.0f,1.0f},
    {1.5f,0.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {-0.0f,1.0f},
  },
  {//equilateral triangle
    {0.0f,  1.0f},
    {0.87f, -0.9f},
    {-0.87f, -1.5f},
    {0.0f, 1.0f}
  },
  {//hexagon
    {-0.5f,0.4f},
    {0.5f,0.5f},
    {1.0f,-0.1f},
    {0.5f,-0.5f},
    {-0.4f,-0.5f},
    {-1.0f,0.0f},
    {-0.5f,0.4f}
  },
  {//isoceles triangle
    {2.0f,  0.0f},
    {-0.5, -1.1f},
    {-0.5f, 0.866025f},
    {2.0f, 0.0f}
  },
  {//rectangle
    {0.0f,2.1f},
    {1.0f,0.1f},
    {0.0f,-0.9f},
    {-1.0f,-0.1f},
    {0.0f,2.1f},
  },
  {//pentagon
    {0.0f,1.0f},
    {1.5f,-0.1f},
    {1.0f,-1.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {0.0f,1.0f},
  },
  {//trapesium
    {0.0f,1.2f},
    {1.3f,0.0f},
    {0.0f,-1.0f},
    {-1.0f,0.1f},
    {0.0f,1.2f},
  },
  {//trapesium2
    {-1.0f,1.0f},
    {1.0f,1.0f},
    {3.0f,-1.0f},
    {-3.0f,-1.0f},
    {-1.0f,1.0f},
  },
  {//regular hexagon
    {1.0f,0.0f},
    {0.5f,-0.866025403859f},
    {-0.5f,-0.866025403859f},
    {-1.0f,0.0f},
    {-0.5f,0.866025403859f},
    {0.5f,0.866025403859f},
    {1.0f,0.0f}
  },
  {//room with a door
    {7.0f,11.0f},
    {7.0f,-12.0f},
    {-7.0f,-12.0f},
    {-7.0f,3.0f},
    {-7.0f,11.0f},
    {7.0f,11.0f},
  },
  {//bathroom with a door and mirror
    {7.0f,11.0f},
    {7.0f,-12.0f},
    {-3.0f,-12.0f},
    {-7.0f,-12.0f},
    {-7.0f,3.0f},
    {-7.0f,11.0f},
    {7.0f,11.0f},
  },//triangle, designed for rose stage
  {
    {1.0f,2.0f},
    {1.0f,-1.0f},
    {-2.0f,-1.0f},
    {1.0f,2.0f}
  },
  {//new perturbed triangle
    {0.0f,  1.0f},
    {0.87f, -0.9f},
    {-0.87f, -2.5f},
    {0.0f, 1.0f}
  },//rectoct
  {
    {1.0f,2.0f},
    {1.0f,-2.0f},
    {0.5f,-2.5f},
    {-0.5f,-2.5f},
    {-1.0f,-2.0f},
    {-1.0f,2.0f},
    {-0.5f,2.5f},
    {0.5f,2.5f},
    {1.0f,2.0f}
  },
  //penrose 1
  {
    {0.0f-0.4045084971874737f-0.5f,0.0f-0.29389262614623657f},
    {0.8090169943749475f-0.4045084971874737f-0.5f,0.5877852522924731f-0.29389262614623657f},
    {0.8090169943749475f+1.0f-0.4045084971874737f-0.5f,0.5877852522924731f-0.29389262614623657f},
    {1.0f-0.4045084971874737f-0.5f,0.0f-0.29389262614623657f},
    {0.0f-0.4045084971874737f-0.5f,0.0f-0.29389262614623657f},
  },
  //penrose 2
  {
    {0.0f-0.6545084971874737f,-0.47552825814757677f},
    {0.30901699437494745f-0.6545084971874737f,0.9510565162951535f-0.47552825814757677f},
    {0.30901699437494745f+1.0f-0.6545084971874737f,0.9510565162951535f-0.47552825814757677f},
    {1.0f-0.6545084971874737f,-0.47552825814757677f},
    {0.0f-0.6545084971874737f,-0.47552825814757677f},
  },
  {//bisquare
    {0.0f,1.0f},
    {1.0f,2.0f},
    {2.0f,1.0f},
    {1.0f,0.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {-0.0f,1.0f},
  },
  {//2x1rect
    {1.0f,2.0f},
    {2.0f,1.0f},
    {0.0f,-1.0f},
    {-1.0f,-0.0f},
    {1.0f,2.0f},
  },
  {//gloryhole
    {-1.0f,1.0f},
    {1.0f,1.0f},
    {1.0f,0.1f},
    {1.0f,-0.1f},
    {1.0f,-1.0f},
    {-1.0f,-1.0f},
    {-1.0f,1.0f}
  },
  {//equilateral triangle with koch  subdivisions
    {1.0f,  0.0f},
    {0.5f, -0.288675f},
    {0.0f, -0.57735f},
    {-0.5, -0.866025f},
    {-0.5, -0.288675f},
    {-0.5, 0.288675f},
    {-0.5f, 0.866025f},
    {0.0f, 0.57735f},
    {0.5f, 0.288675f},
    {1.0f, 0.0f}
  },
  {//equilateral triangle with koch  subdivisions on only two sides
    {1.0f,  0.0f},
    {-0.5, -0.866025f},
    {-0.5, -0.288675f},
    {-0.5, 0.288675f},
    {-0.5f, 0.866025f},
    {0.0f, 0.57735f},
    {0.5f, 0.288675f},
    {1.0f, 0.0f}
  },
  {//septagon
    {0.6234898018587336,0.7818314824680298},
    {1.0,-2.4492127076447545e-16},
    {0.6234898018587334,-0.7818314824680299},
    {-0.2225209339563146,-0.9749279121818236},
    {-0.9009688679024191,-0.433883739117558},
    {-0.900968867902419,0.43388373911755823},
    {-0.22252093395631434,0.9749279121818236},
    {0.6234898018587336,0.7818314824680298}
  },
  {//octagon
    {0.7071067811865476,0.7071067811865475},
    {1.0,-2.4492127076447545e-16},
    {0.7071067811865474,-0.7071067811865477},
    {-1.836909530733566e-16,-1.0},
    {-0.7071067811865477,-0.7071067811865475},
    {-1.0,1.2246063538223773e-16},
    {-0.7071067811865475,0.7071067811865476},
    {6.123031769111886e-17,1.0},
    {0.7071067811865476,0.7071067811865475},
  },
  {//nonagon
    {0.766044443118978,0.6427876096865393},
    {1.0,-2.4492127076447545e-16},
    {0.7660444431189778,-0.6427876096865396},
    {0.17364817766692997,-0.9848077530122081},
    {-0.5000000000000004,-0.8660254037844384},
    {-0.9396926207859084,-0.34202014332566866},
    {-0.9396926207859083,0.3420201433256689},
    {-0.4999999999999998,0.8660254037844387},
    {0.17364817766693041,0.984807753012208},
    {0.766044443118978,0.6427876096865393},
  },
  {//decagon
    {0.8090169943749475,0.5877852522924731},
    {1.0,-2.4492127076447545e-16},
    {0.8090169943749473,-0.5877852522924734},
    {0.30901699437494723,-0.9510565162951536},
    {-0.30901699437494756,-0.9510565162951535},
    {-0.8090169943749476,-0.587785252292473},
    {-1.0,1.2246063538223773e-16},
    {-0.8090169943749473,0.5877852522924732},
    {-0.30901699437494734,0.9510565162951536},
    {0.30901699437494745,0.9510565162951535},
    {0.8090169943749475,0.5877852522924731},
  },
};

