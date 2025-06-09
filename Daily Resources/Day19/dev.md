# REST APIs & HTTP Status Codes | Web Development Guide

## 📚 Overview

**REST (Representational State Transfer)** is a set of rules for building web APIs. Think of it as the "grammar" for how frontend and backend communicate. Combined with HTTP status codes, it creates predictable, scalable web services.

## 🎯 Key Concepts

### HTTP Methods (CRUD)
* **GET**: Read data - `/api/users` (get all users)
* **POST**: Create data - `/api/users` (create new user)  
* **PUT**: Update entire resource - `/api/users/123`
* **PATCH**: Update specific fields - `/api/users/123`
* **DELETE**: Remove data - `/api/users/123`

### Status Code Categories
* **2xx**: Success (200 OK, 201 Created, 204 No Content)
* **4xx**: Client Error (400 Bad Request, 401 Unauthorized, 404 Not Found)
* **5xx**: Server Error (500 Internal Server Error, 503 Service Unavailable)

## 💡 Why This Matters

* **Predictability** - Developers know what to expect from your API
* **Debugging** - Clear status codes make troubleshooting easier
* **Standards** - Following REST makes your API familiar to other developers
* **Scalability** - Stateless design supports horizontal scaling

## 📖 Essential Learning

* [What is REST API? - Simply Explained](https://youtu.be/lsMQRaeKNDk) - 8min beginner-friendly overview
* [HTTP Status Codes Explained](https://youtu.be/wJa5CTIFj7U) - 12min comprehensive guide to all status codes

## 🎥 In-Depth Tutorials
* [REST API Tutorial - Programming with Mosh](https://youtu.be/SLwpqD8n3d0) - 1hr complete REST fundamentals

## 🔧 Quick Examples

```javascript
// Basic CRUD API
app.get('/api/users/:id', (req, res) => {
  const user = getUserById(req.params.id);
  if (!user) return res.status(404).json({ error: 'User not found' });
  res.status(200).json(user);
});

app.post('/api/users', (req, res) => {
  const { name, email } = req.body;
  if (!name || !email) {
    return res.status(400).json({ error: 'Name and email required' });
  }
  const newUser = createUser({ name, email });
  res.status(201).json(newUser);
});

app.delete('/api/users/:id', (req, res) => {
  const deleted = deleteUser(req.params.id);
  if (!deleted) return res.status(404).json({ error: 'User not found' });
  res.status(204).send(); // No content
});
```

## 🚀 Quick Task

Create a simple Todo API:

```javascript
// TODO: Complete these endpoints
app.get('/api/todos', (req, res) => {
  // Return all todos with 200
});

app.post('/api/todos', (req, res) => {
  // Create todo, return 201 if success, 400 if missing data
});

app.delete('/api/todos/:id', (req, res) => {
  // Delete todo, return 204 if success, 404 if not found
});
```

## 📊 Essential Status Codes

| Code | Name | Use Case |
|------|------|----------|
| 200 | OK | Successful GET/PUT |
| 201 | Created | Successful POST |
| 204 | No Content | Successful DELETE |
| 400 | Bad Request | Invalid data sent |
| 401 | Unauthorized | Login required |
| 404 | Not Found | Resource doesn't exist |
| 500 | Server Error | Something broke server-side |

## ⚠️ Common Mistakes

```javascript
// ❌ Bad
app.get('/api/getUsers')           // Don't use verbs in URLs
res.status(200).json({error: 'Not found'})  // Wrong status code

// ✅ Good  
app.get('/api/users')              // Use nouns, HTTP method shows action
res.status(404).json({error: 'Not found'})  // Correct status code
```

## 📖 Resources

* [REST API Tutorial](https://restfulapi.net/) - Complete REST guide
* [HTTP Status Codes - MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status) - Official documentation
* [JSONPlaceholder](https://jsonplaceholder.typicode.com/) - Practice API testing
