#ifndef HTTPMETHOD
#define HTTPMETHOD



struct HttpMethod{
enum Type {
   GET,
   POST,
   DELETE,
   PUT
};

static bool isValidRequestFor(Type httpMethod) {
   return POST == (httpMethod) || PUT == (httpMethod) || DELETE == (httpMethod);
}
};






#endif // HTTPMETHOD

