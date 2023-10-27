class Hierarchy
{
private:
    char prisoner_class;
    Hierarchy *left, *right;
public:
    Hierarchy(char prisoner_class)
    {
        this->prisoner_class=prisoner_class;
    }
    // ~Hierarchy();
    friend class Hierarchial_tree;
};

class Hierarchial_tree
{
private:
    Hierarchy *hierarchial_root;
public:
    Hierarchial_tree();
    // ~Hierarchial_tree();
    void add_hierarchy(Hierarchy* &chunk, int index);
};
