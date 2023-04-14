
*******************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class Photo
{
    
//Creating list to handle pointers
class PointersList
{
    
      //Craeting Node
   class Node
   {
       public:
       string cat_name;
       Photo* address; 
       Node* next;
   };  
  public:
  Node* first;
  PointersList()
  {
      first=NULL;
  }
  void add(string str,Photo* add)
  {
      //Craeting new Node
     Node* new_node=new Node();
     new_node->cat_name=str;
     new_node->address=add;
     new_node->next=NULL;
     
    if(first==NULL)
     {
         first=new_node;
     }
     else
     {
        Node* node=first;
        //Getting last node
        while(node->next!=NULL)
        {
            node=node->next;
        }
        node->next=new_node;
         
     }
  }
  Photo* getAddress(string cat_name)
  {
          Node* node=first;
        while(node!=NULL)
        {
            if(node->cat_name==cat_name)
              break;
        }
      if(node==NULL)
      return NULL; 
      else
        return node->address;
  } 
  void updateAddressIn(string cat_name,Photo* address)
  {
    Node* node=first;
    while(node!=NULL)
    {
            if(node->cat_name==cat_name)
              node->address=address;
    }
  }
    
};
  
  
  
  
  
  //Creating Stringlist
class StringList
{
 
    //Craeting Node
   class Node
   {
       public:
       string data;
       Node* next;
   };
   
  public:
  Node* first;
  StringList()
  {
      first=NULL;
  }
  void add(string str)
  {
      //Craeting new Node
     Node* new_node=new Node();
     new_node->data=str;
     new_node->next=NULL;
     
     if(first==NULL)
     {
         first=new_node;
     }
     else
     {
        Node* node=first;
        //Getting last node
        while(node->next!=NULL)
        {
            node=node->next;
        }
        node->next=new_node;
         
     }
     
  }
  void display()
  {
    Node* node=first;
     //Traversing whole list using while loop
        while(node!=NULL)
        {
            cout<<node->data<<" ";
            node=node->next;
        } 
  }
  string getAt(int n)
  {
          Node* node=first;
        for(int i=1;i<n;i++)
        {
            node=node->next;
        }
      return node->data;  
  }
  int sizeMoreThanOne()
  {
      if(first->next==NULL)
      return 0;
      else
       return 1;
  }
  int isExists(string str)
  {
    Node* node=first; 
    while(node!=NULL)
    {
        if(node->data==str)
        return 1;
        node=node->next;
    }
    return 0;
  }
  void Remove(string str)
  {
    Node* node=first; 
    if(first->data==str)
       first=first->next;
    while(node->next!=NULL)
    {
        if(node->next->data==str)
         {
             node->next=node->next->next;
             return;
         }
        node=node->next;
    }  
  }
    
};

    
  //Photo instances  
  public:
          string title;
          string path;
          tm* date;
          StringList* cat_list;
          PointersList* pointersList;
      Photo(string t,string p)
      {
        title=t;
        path=p;
           //getting date
           time_t now = time(0);
           date= localtime(&now);
           
        cat_list=new StringList();
        pointersList=new PointersList();
      }
    
};





class Category
{
       public :
          string category_name;
          Photo* first;
        Category()
       {
           category_name="Default Category";
           cout<<"Default Category Created Successfully!\n";
           first=NULL;
           
       }
       Category(string cat_name)
       {
           category_name=cat_name;
           first=NULL;
         cout<<cat_name<<" Category Created Successfully!\n";

       }
       void addPhoto(Photo* photo)
       {
         //Updating photo's category list
         photo->cat_list->add(category_name);
         //Addding first photo
         if(first==NULL)
         {
             first=photo;
            cout<<photo->title<<" added to Catagory "<<category_name<<"!\n";

         }
         else
         {
              Photo* current_photo=first;
              //Accesing last photo of current category
              while(current_photo->pointersList->getAddress(category_name)!=NULL)
              {
                 current_photo=current_photo->pointersList->getAddress(category_name);
              }
             //Adding Photo
             current_photo->pointersList->add(category_name,photo);
            cout<<photo->title<<" added to Catagory "<<category_name<<"!\n";
         }
         
           
           
       }
       
};









//Creating list for categories
class CategoriesList
{
   //Craeting Node
   class Node
   {
       public:
       Category* category;
       Node* next;
   };
   
  public:
  Node* first;
  CategoriesList()
  {
      first=NULL;
  } 
///////////////////////////////delete photo////////////////////////////////////////
  void deletePhoto(Photo* photo)
  {
      Node* node=first;
      //accessing all cataegories of current photo
      while(node!=NULL)
      {
         if(photo->cat_list->isExists(node->category->category_name)==1) 
         {
             Category* category=node->category;
             Photo* current_photo=category->first;
             //deleting first photo on condition based
             if(current_photo==photo)
             {
                category->first=photo->pointersList->getAddress(node->category->category_name); 
             }
             //Accesing and deleting photo
             while(current_photo->pointersList->getAddress(node->category->category_name)!=NULL)
             {
                 if(current_photo->pointersList->getAddress(node->category->category_name)==photo)
                 {
                 Photo* next_photo=photo->pointersList->getAddress(node->category->category_name);
                 current_photo->pointersList->updateAddressIn(node->category->category_name,next_photo);
                 break;
                 }
             }
             
         }
          
          
      }
  }
///////////////////add category/////////////////////////////////////
    void addCategory(Category* category)
  {
      //Craeting new Node
     Node* new_node=new Node();
     new_node->category=category;
     new_node->next=NULL;
     
     if(first==NULL)
     {
         first=new_node;
     }
     else
     {
        Node* node=first;
        //Getting last node
        while(node->next!=NULL)
        {
            node=node->next;
        }
        node->next=new_node;
         
     }
  }
  
  
  
  ///////////////////delete category/////////////////////////////////////
  void deleteCategory(Category* category)
  {
      if(first==NULL)
      {
        cout<<"No Such a Category to delete!";  
        return;
      }
      //Accesing catagory to delete from list
      Node* node=first;
      int cat_found=0;
      while(node->next!=NULL)
      {
         if(node->next->category==category) 
         {
             cat_found=1;
             break;
         }
         node=node->next;
      }
      if(cat_found==1)
      {
        //node+1 is category to delete
        Photo* current_photo=category->first;
        //Deleting first photo conditioned based
        if(current_photo->cat_list->sizeMoreThanOne()==0)
        category->first=current_photo->pointersList->getAddress(category->category_name);
        
        
        //Accesing all photos of category exept last through while loop and deleting condition based
        while(current_photo->pointersList->getAddress(category->category_name)!=NULL)
        {
            if(current_photo->pointersList->getAddress(category->category_name)->cat_list->sizeMoreThanOne()==0)
            {
                Photo* next_photo=current_photo->pointersList->getAddress(category->category_name)->pointersList->getAddress(category->category_name);
                current_photo->pointersList->updateAddressIn(category->category_name,next_photo);
            }
            
            
           current_photo=current_photo->pointersList->getAddress(category->category_name);
            
            
        }
        
        
        //deleting Node(Category)
        node->next=node->next->next;
      }
      else
      {
        cout<<"No Such a Category to delete!";  
  
      }
      
  }
  ///////////////////////Method to check availibilty of photo in category//////////////////
  int isPhotoExistsInCat(Category* cat,Photo* photo)
  {
      Photo* current_photo=cat->first;
       while(current_photo!=NULL)
    {
        if(current_photo==photo)
        return 1;
        current_photo=current_photo->pointersList->getAddress(cat->category_name);
    }
    return 0;
  }
    /////////////////////////////Display Photo///////////////////////
void displayPhoto(Photo* photo)
{
    
}
  /////////////////////////////Display Category///////////////////////
void displayCategory(Category* category)
{
    Photo* current_photo=category->first;
     while(current_photo!=NULL)
    {
        //displaying photo
        displayPhoto(current_photo);
        current_photo=current_photo->pointersList->getAddress(category->category_name);
    }
}
/////////////////////////////Display union of photos of cataegories///////////////////////
void displayUnion(Category* category1,Category* category2)
{
    Category* union_cat=new Category("");
    Photo* current_photo=category1->first;
    //adding photos of category1
    while(current_photo!=NULL)
    {
        union_cat->addPhoto(current_photo);
        current_photo=current_photo->pointersList->getAddress(category1->category_name);
    }
    current_photo=category2->first;
    //adding photos of category2 if not already exists
    while(current_photo!=NULL)
    {
        if(isPhotoExistsInCat(union_cat,current_photo)==0)
        union_cat->addPhoto(current_photo);
        current_photo=current_photo->pointersList->getAddress(category1->category_name);
    }
    
    //display union
    displayCategory(union_cat);
    cout<<"Displaying Union of "<<category1->category_name<<" and "<<category2->category_name;
}
 /////////////////////////////Display Intesection of photos of cataegories///////////////////////
void displayIntersect(Category* category1,Category* category2)
{
      Category* intersect_cat=new Category("");
   Photo* current_photo=category1->first;
    //adding common photos in intersect_cat
    while(current_photo!=NULL)
    {
        if(isPhotoExistsInCat(category2,current_photo)==1)
        intersect_cat->addPhoto(current_photo);
       current_photo=current_photo->pointersList->getAddress(category1->category_name);
 
    }
    
        //display intersect
       displayCategory(intersect_cat);
    
cout<<"Displaying Intersect of "<<category1->category_name<<" and "<<category2->category_name;

    
}
  
 Category* getAddressAt(int n)
  {
        Node* node=first;
        for(int i=1;i<n;i++)
        {
            node=node->next;
        }
      return node->category;
  }
    
};


////////////////////////////Addding category to photo///////////////////
void addCategory(Photo* photo,Category* category)
{
    //updating photo's cat_list
    photo->cat_list->add(category->category_name);
    //accessing last photo of category
      Photo* current_photo=category->first;
      while(current_photo->pointersList->getAddress(category->category_name)!=NULL)
      {
          current_photo=current_photo->pointersList->getAddress(category->category_name);
      }
      //Adding photo at end of category
      current_photo->pointersList->updateAddressIn(category->category_name,photo);
}
////////////////////////////Delete category of photo///////////////////
void deleteCategory(Photo* photo,Category* category)
{
    //updating photo's cat_list
    photo->cat_list->Remove(category->category_name);
    //Acessing photo in category
     Photo* current_photo=category->first;
     if(current_photo==photo)
     {
       category->first=photo->pointersList->getAddress(category->category_name);  
     }
     while(current_photo->pointersList->getAddress(category->category_name)!=NULL)
     {
         if(current_photo->pointersList->getAddress(category->category_name)->pointersList->getAddress(category->category_name)==photo)
         {
            //Updating links
            Photo* next_photo=current_photo->pointersList->getAddress(category->category_name)->pointersList->getAddress(category->category_name);
            current_photo->pointersList->updateAddressIn(category->category_name,next_photo);
         }
     }
    
}





int main()
{
    //Creating catagories list
    CategoriesList* cat_list=new CategoriesList();
    //Creating default catagory and adding to list
    cat_list->addCategory(new Category());
    //Creating Family catagory and adding to list
    cat_list->addCategory(new Category("Family"));
    //Creating Friends catagory and adding to list
    cat_list->addCategory(new Category("Friends"));
    //Creating Trip catagory and adding to list
    cat_list->addCategory(new Category("Trip"));
    
    //User defined Category
    string cat_name;
    cout<<"Enter Category Name you want to create:";
    cin>>cat_name;
    //Creating Trip catagory and adding to list
    cat_list->addCategory(new Category(cat_name));
    
    
    Photo* photo1=new Photo("My Photo","D:/images/picture1.jpg");
    Photo* photo2=new Photo("Cousin's Photo","D:/images/picture2.jpg");
    //User defined title of Photo
    string photo_title;
    cout<<"Enter Title of Photo:";
    cin>>photo_title;
    Photo* photo3=new Photo(photo_title,"D:/images/picture3.jpg");
    //Adding photo1 to Family category
    cat_list->getAddressAt(2)->addPhoto(photo1);
    //Adding randomly
    cat_list->getAddressAt(1)->addPhoto(photo2);
    cat_list->getAddressAt(3)->addPhoto(photo3);
    cat_list->getAddressAt(2)->addPhoto(photo1);
    //Deleting category at 3 in list
    cat_list->deleteCategory(cat_list->getAddressAt(3));
    //Displaying union
    //cat_list->displayUnion(cat_list->getAddressAt(1),cat_list->getAddressAt(2));
    //Displaying Intersection
    //cat_list->displayIntersect(cat_list->getAddressAt(1),cat_list->getAddressAt(4));
    
    return 0;
}
