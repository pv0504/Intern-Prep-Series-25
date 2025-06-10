# Authentication: Sessions vs JWT | Web Development Guide

## 📚 Overview

**Authentication** is how your app verifies "who you are" while **authorization** determines "what you can do". Sessions and JWT (JSON Web Tokens) are two popular ways to handle user authentication in web applications. Think of them as two different ways to remember that you've already logged in.

## 🎯 Key Concepts

### Session-Based Authentication
* **Server stores user state** in memory/database
* **Session ID** sent to client as cookie
* **Stateful** - server remembers who's logged in
* **Traditional approach** - been around since early web days

### JWT Authentication  
* **Token contains user info** - no server storage needed
* **Self-contained** - all info is in the token itself
* **Stateless** - server doesn't store session data
* **Modern approach** - popular in SPAs and mobile apps

## 💡 Why This Matters

* **Scalability** - JWT scales better across multiple servers
* **Security** - Different attack vectors and protection methods
* **Performance** - Sessions require database lookups, JWT doesn't
* **Mobile/API** - JWT works better for mobile apps and APIs

## 📖 Essential Learning

* [Session vs JWT Authentication - Simply Explained](https://youtu.be/UBUNrFtufWo) - comparison of both approaches
* [What is JWT? - Auth0](https://youtu.be/7Q17ubqLfaM) - JWT fundamentals 
* [Sessions and Cookies Explained](https://youtu.be/64veb6tKTm0) - deep dive into session mechanics

## 🎥 In-Depth Tutorials
* [Complete Authentication Tutorial - WebDevSimplified](https://youtu.be/Ud5xKCYQTjM) - implementation 

## 🔧 Implementation Examples

### Session-Based Authentication

```javascript
// Setup
app.use(session({
  secret: 'your-secret-key',
  cookie: { maxAge: 24 * 60 * 60 * 1000 } // 24 hours
}));

// Login
app.post('/login', async (req, res) => {
  const user = await findUser(req.body.email, req.body.password);
  if (!user) return res.status(401).json({ error: 'Invalid credentials' });
  
  req.session.userId = user.id; // Store in session
  res.json({ message: 'Login successful' });
});

// Protected route
app.get('/profile', (req, res) => {
  if (!req.session.userId) {
    return res.status(401).json({ error: 'Login required' });
  }
  res.json({ userId: req.session.userId });
});

// Logout
app.post('/logout', (req, res) => {
  req.session.destroy();
  res.json({ message: 'Logged out' });
});
```

### JWT Authentication

```javascript
const JWT_SECRET = 'your-jwt-secret';

// Login
app.post('/login', async (req, res) => {
  const user = await findUser(req.body.email, req.body.password);
  if (!user) return res.status(401).json({ error: 'Invalid credentials' });
  
  const token = jwt.sign({ userId: user.id }, JWT_SECRET, { expiresIn: '24h' });
  res.json({ token });
});

// Middleware
function authenticateToken(req, res, next) {
  const token = req.headers['authorization']?.split(' ')[1];
  if (!token) return res.status(401).json({ error: 'Token required' });
  
  jwt.verify(token, JWT_SECRET, (err, user) => {
    if (err) return res.status(403).json({ error: 'Invalid token' });
    req.user = user;
    next();
  });
}

// Protected route
app.get('/profile', authenticateToken, (req, res) => {
  res.json({ userId: req.user.userId });
});
```

### Frontend Usage

```javascript
// Sessions - cookies handled automatically
fetch('/login', {
  method: 'POST',
  credentials: 'include', // Important!
  body: JSON.stringify({ email, password })
});

// JWT - manual token handling
const response = await fetch('/login', {
  method: 'POST',
  body: JSON.stringify({ email, password })
});
const { token } = await response.json();
localStorage.setItem('token', token);

// Use JWT token
fetch('/profile', {
  headers: { 'Authorization': `Bearer ${localStorage.getItem('token')}` }
});
```

## 🚀 Quick Task

Implement both authentication methods for a simple user system:

```javascript
// TODO: Complete both implementations

// Session version
app.post('/register', async (req, res) => {
  // Hash password, save user, create session
});

// JWT version  
app.post('/register', async (req, res) => {
  // Hash password, save user, return JWT token
});

// Test both approaches and compare:
// 1. Check browser dev tools for cookies vs localStorage
// 2. Test logout functionality
// 3. Try accessing protected routes
```

## 📊 Sessions vs JWT Comparison

| Feature | Sessions | JWT |
|---------|----------|-----|
| **Storage** | Server-side | Client-side |
| **Scalability** | Harder (sticky sessions) | Easier (stateless) |
| **Security** | Server controls everything | Token can't be revoked easily |
| **Performance** | Database lookup needed | No server storage |
| **Mobile/API** | Requires cookies | Works anywhere |
| **Size** | Small cookie | Larger token |
| **Logout** | Easy (destroy session) | Complex (blacklisting) |

## ⚠️ Security Best Practices

### Sessions
```javascript
// ✅ Secure session config
app.use(session({
  secret: process.env.SESSION_SECRET, // Use environment variables
  resave: false,
  saveUninitialized: false,
  cookie: { 
    secure: true,        // HTTPS only in production
    httpOnly: true,      // Prevent XSS attacks
    maxAge: 1800000,     // 30 minutes
    sameSite: 'strict'   // CSRF protection
  }
}));
```

### JWT
```javascript
// ✅ Secure JWT practices
const token = jwt.sign(
  { userId: user.id }, // Don't include sensitive data
  process.env.JWT_SECRET,
  { 
    expiresIn: '15m',    // Short expiration
    issuer: 'your-app',
    audience: 'your-users'
  }
);

// Use refresh tokens for longer sessions
const refreshToken = jwt.sign(
  { userId: user.id, type: 'refresh' },
  process.env.REFRESH_SECRET,
  { expiresIn: '7d' }
);
```

## ⚠️ Common Mistakes

```javascript
// ❌ Bad practices
// Storing passwords in JWT
const token = jwt.sign({ password: user.password }, secret);

// No token expiration
const token = jwt.sign({ userId: user.id }, secret); // Never expires!

// Storing JWT in localStorage (XSS vulnerable)
localStorage.setItem('token', token);

// ✅ Better approaches
// Only store non-sensitive data
const token = jwt.sign({ userId: user.id, role: user.role }, secret, { expiresIn: '1h' });

// Use httpOnly cookies for JWT (when possible)
res.cookie('token', token, { httpOnly: true, secure: true });
```

## 📖 Quick Decision Guide

**Choose Sessions when:**
- Building traditional web apps
- Security is top priority
- You have a single server/domain
- Users expect to be "logged out" from other devices

**Choose JWT when:**
- Building APIs or SPAs
- You need to scale across multiple servers
- Building mobile apps
- You want stateless architecture

## 📖 Resources

### Essential Reading
* [Session vs JWT - Auth0 Blog](https://auth0.com/blog/cookies-vs-tokens-definitive-guide/) - Comprehensive comparison
* [JWT Security Best Practices](https://auth0.com/blog/a-look-at-the-latest-draft-for-jwt-bcp/) - Security guidelines
* [Express Session Documentation](https://www.npmjs.com/package/express-session) - Official session middleware docs

### Tools for Testing
* [JWT.io](https://jwt.io/) - Decode and verify JWT tokens
* [Postman](https://www.postman.com/) - Test your authentication APIs
* [Chrome DevTools](https://developer.chrome.com/docs/devtools/) - Inspect cookies and localStorage
