class Fraise {
    private :
    pos_fraise:Position 

    public:
    Fraise();
    ~Fraise();
    Position get_Position_Fraise();
    void set_Position_Fraise();
    bool positionValide(const & Labyrinthe);
    void gauche(const & Labyrinthe);
    void droit(const & Labyrinthe);
    void haut(const & Labyrinthe);
    void bas(const & Labyrinthe);



