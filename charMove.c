struct player
{
    char pos_x;
    char pos_y;
    char old_x;
    char old_y;
};

void move_player(struct player *p, char direction)
{
    p->old_x = p->pos_x;
    p->old_y = p->pos_y;
    switch (direction)
    {
    case 'w':
        p->pos_x--;
        break;
    case 's':
        p->pos_x++;
        break;
    case 'a':
        p->pos_y--;
        break;
    case 'd':
        p->pos_y++;
        break;
    }
}

void map_update(char map[5][5], struct player *p)
{
    map[p->old_x][p->old_y] = " ";
    map[p->pos_x][p->pos_y] = "p";
}