#include<iostream>
using namespace std;

struct AVL 
{
   int d;
   struct AVL *l;
   struct AVL *r;
}*r;

class AVL_Tree {
   public:
       int height(AVL* temp) 
       {
           int h = 0;
           if (temp != NULL) 
           {
               int l_height = height(temp->l);
               int r_height = height(temp->r);
               int max_height = max(l_height, r_height);
               h = max_height + 1;
           }
           return h;
       }

       int difference(AVL* temp) 
       {
           int l_height = height(temp->l);
           int r_height = height(temp->r);
           return (l_height - r_height);
       }

       AVL* RightRightRotate(AVL* p) 
       {
           AVL* t;
           t = p->r;
           p->r = t->l;
           t->l = p;
           cout << "Right-Right Rotation";
           return t;
       }

       AVL* LeftLeftRotate(AVL* p) 
       {
           AVL* t;
           t = p->l;
           p->l = t->r;
           t->r = p;
           cout << "Left-Left Rotation";
           return t;
       }
      
       AVL* LeftRightRotate(AVL* p) 
       {
           AVL* t;
           t = p->l;
           p->l = RightRightRotate(t);
           cout << "Left-Right Rotation";
           return LeftLeftRotate(p);
       }

       AVL* RightLeftRotate(AVL* p) 
       {
           AVL* t;
           t = p->r;
           p->r = LeftLeftRotate(t);
           cout << "Right-Left Rotation";
           return RightRightRotate(p);
       }
       AVL* balance(AVL* temp) 
       {
           int diff = difference(temp);
           if (diff > 1) 
           {
               if (difference(temp->l) > 0)
               {
                   temp = LeftLeftRotate(temp);
               }
               else
               {
                   temp = LeftRightRotate(temp);
               }
           }
           else if (diff < -1)
           {
               if (difference(temp->r) > 0)
               {
                   temp = RightLeftRotate(temp);
               }
               else
               {
                   temp = RightRightRotate(temp);
               }
           }
           return temp;
       }
       AVL* insert(AVL* r, int num) 
       {
           if (r == NULL) {
               r = new AVL;
               r->d = num;
               r->l = NULL;
               r->r = NULL;
               return r;
           }
           else if (num < r->d) {
               r->l = insert(r->l, num);
               r = balance(r);
           }
           else if (num >= r->d) {
               r->r = insert(r->r, num);
               r = balance(r);
           } return r;
       }
      
       void show(AVL* p, int l) 
       {
           int i;
           if (p != NULL) 
           {
               show(p->r, l + 1);
               cout << " ";
               if (p == r)
               {
                   cout << "Root -> ";
               }
               for (i = 0; i < l && p != r; i++)
               {
                   cout << " ";
               }
               cout << p->d;
               show(p->l, l + 1);
           }
       }

      AVL_Tree() 
      {
         r = NULL;
      }
};


int main() {
   int c, i;
   AVL_Tree AVL;
   while (1) 
   {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c)
      {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = AVL.insert(r, i);
         break;
         case 2:
            if (r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            AVL.show(r, 1);
            cout<<endl;
         break;
         case 3:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}
