
/* Base object, containing its coordinates */
class Object
{
    public :
        Object(int pos_x,
                int pos_y,
                int len_x,
                int len_y);

        // Getters
        /// {
        int pos_x_get(void);
        int pos_y_get(void);
        int len_y_get(void);
        int len_x_get(void);
        /// }

    protected :
        int pos_x_;
        int pos_y_;
        int len_x_;
        int len_y_;
};
