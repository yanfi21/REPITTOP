#include <iostream>
 using namespace std;
 
 class User;
 class Post {
  friend User;
 protected:
  string text;
  int date;
  int likes;
  int comments;
  string* commenttext;
 public:
  Post() {
   text = "";
   date = 0;
   likes = 0;
   comments = 0;
   commenttext = nullptr;
  }
  Post(string text, int date, int likes, int comments, string* commenttext) {
   this->text = text;
   this->date = date;
   this->likes = likes;
   this->comments = comments;
   this->commenttext = commenttext;
  }
 };
 class Admin;
 class User {
  friend Admin;
 protected:
  string login;
  string password;
  string name;
  Post* Posts;
  Post* liked;
  int likes;
  int posts;
 public:
  User() {
   login = "";
   password = "";
   name = "";
   Posts = nullptr;
   liked = nullptr;
   likes = 0;
   posts = 0;
  }
  User(string login, string password, string name, Post* Posts, Post* liked, int likes, int posts) {
   this->login = login;
   this->password = password;
   this->name = name;
   this->Posts = Posts;
   this->liked = liked;
   this->likes = likes;
   this->posts = posts;
  }
  void CreatePost(const Post& newPost) {
   Post* newPosts = new Post[posts + 1];
   for (int i = 0; i < posts; i++)
    newPosts[i] = Posts[i];
   newPosts[posts] = newPost;
   delete[] Posts;
   Posts = newPosts;
   posts++;
  }
  void DoLike(Post newlike, Post& post) {
   Post* newliked = new Post[likes++];
   for (int j = 0; j < likes; j++)
    newliked[j] = liked[j];
   newliked[likes + 1] = newlike;
   post.likes++;
  }
  void DoComment(string newcomment, Post& post) {
   string* newcomments = new string[post.comments++];
   for (int i = 0; i < post.comments; i++)
    newcomments[i] = post.commenttext[i];
   newcomments[post.comments] = newcomment;
   post.comments++;
  }
  void PrintPost() {
   for (int i = 0; i < posts; i++)
    cout << Posts[i].text;
  }
 };
 class Admin;
 class Society {
  friend Admin;
 private:
  int users;
  User* Users;
  int likes;
  Post Posts;
  int posts;
 };
 
 class Admin : public User {
 private:
  int societies;
 public:
  void BanUser(User& user) {
   user.login = "";
   user.liked = 0;
   user.name = "";
   user.password = "";
   user.posts = 0;
   user.likes = 0;
   user.Posts = 0;
  }
 };
 
 int main()
 {
  setlocale(LC_ALL, "RUS");
  Post post{ "hello",180325,0,0,nullptr };
  User firstuser{ "321ytrewq","123qwerty" ,"user",nullptr,nullptr,0,0 };
  Post firstpost{ "hello",180325,0,0,nullptr };
  firstuser.CreatePost(firstpost);
  firstuser.PrintPost();
 }
