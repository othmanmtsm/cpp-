class Cercle{
    Point c;
    float r;
public:
    Cercle(Point, float);
    float gerR();
    void changeR(float);
    Point getCentre();
    void changeC(Point);
    float getSurface();
    float getPerimetre();
    bool egal(Cercle);
    int apparenceInOut(Point);
    void affiche();
};