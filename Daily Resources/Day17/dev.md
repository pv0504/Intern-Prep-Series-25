# 👨‍🏫 PART 0: What Is Docker? Why Should You Care?

## ❓ What problem does Docker solve?

Let’s say you build a project on your laptop, and it works great. You send it to your friend…

> Boom. "Bro, it's not working."  
> “Missing Python version, Node modules, MongoDB not installed, PATH error…”

**Docker solves this** by wrapping **your code + environment** into a **container** that runs **the same** anywhere: your laptop, your friend’s laptop, or a production server.

> Think of it like **a portable mini-computer running just your app**.

---

# 🚀 PART 1: Install Docker

## ✅ Prerequisites

1.  Install **Docker Desktop**:

    - [Windows / Mac](https://www.docker.com/products/docker-desktop)
    - Linux: install via `apt`, `dnf`, etc.

2.  Run:

    ```bash
    docker --version

    ```

    Output should be like: `Docker version 24.x.x`

---

# 🧱 PART 2: Anatomy of a Dockerized Project

## Let’s create a **simple web server** in Python Flask.

### 📁 Folder structure:

```
flask-app/
├── app.py
├── requirements.txt
├── Dockerfile
└── .dockerignore

```

---

## ✍️ Step 1: Write the App

### `app.py`

```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def home():
    return "Hello Docker!"

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000)

```

### `requirements.txt`

```
flask==2.3.2

```

---

## ✍️ Step 2: Dockerfile (the recipe)

### `Dockerfile`

```Dockerfile
# Use official Python image
FROM python:3.11-slim

# Set working directory in container
WORKDIR /app

# Copy and install dependencies
COPY requirements.txt .
RUN pip install -r requirements.txt

# Copy the app code
COPY . .

# Expose the port Flask uses
EXPOSE 5000

# Run the app
CMD ["python", "app.py"]

```

---

## ✍️ Step 3: .dockerignore

Just like `.gitignore`, but for Docker. Helps avoid sending unnecessary files to the image.

### `.dockerignore`

```
__pycache__/
*.pyc
.env
.git

```

---

# 🏗️ PART 3: Build & Run the Docker Container

From inside the `flask-app` folder:

### 🔨 Build the Docker image:

```bash
docker build -t flask-docker-app .

```

### 🚀 Run the image as a container:

```bash
docker run -p 5000:5000 flask-docker-app

```

Now go to:  
👉 `http://localhost:5000`  
✅ You’ll see: **Hello Docker!**

---

# 🧠 UNDERSTAND WHAT JUST HAPPENED

Thing

What it did

`docker build`

Compiled your app + environment into an image

`docker run`

Launched a container (running instance of the image)

`-p 5000:5000`

Exposed your local port to the container's port

---

# 🧰 PART 4: Typical Workflow in Dev Teams

Let’s say you're joining a backend team.

You **never** run code manually like:

```bash
pip install flask
python app.py

```

Instead, you clone repo and run:

```bash
docker build -t backend-service .
docker run -p 5000:5000 backend-service

```

> This gives you **confidence** your app works in **clean environments**, just like prod.

---

# 🔄 PART 5: Dev vs Prod Container

## 🧪 Dev: You want **hot reload**, debugging, logs

### Use `docker-compose.yml` for multi-container (e.g., with database):

```yaml
version: "3"
services:
  web:
    build: .
    ports:
      - "5000:5000"
    volumes:
      - .:/app
    command: flask run --host=0.0.0.0
```

### Run:

```bash
docker-compose up

```

> 🚀 Instant restart when code changes!

---

## 🚀 Prod: You want **fast, lightweight containers**

Use:

```Dockerfile
FROM python:3.11-slim
RUN pip install flask
COPY . .
CMD ["gunicorn", "app:app"]

```

Use `gunicorn` for production servers, not Flask dev server.

---

# 📦 PART 6: Sharing & Publishing

## Push your Docker image to Docker Hub:

```bash
docker tag flask-docker-app yourusername/flask-docker-app
docker push yourusername/flask-docker-app

```

Anyone can now pull & run it:

```bash
docker pull yourusername/flask-docker-app
docker run -p 5000:5000 yourusername/flask-docker-app

```

---

# 🎓 PART 7: What Interviewers Want to See

Question they'll ask

What they want

"Have you used Docker?"

Yes, containerized full-stack app

"How did you manage dependencies?"

Via Dockerfile + `pip install`

"How did you set up your dev env?"

docker-compose, volume mounts

"Did you use Docker with Git?"

Yes. Versioned app + Dockerfile on GitHub

"Can you show a demo?"

`git clone` + `docker build` + `docker run` = 💥

---

# 📌 PART 8: Real-World Practice You Must Do

✅ Create your own project:

- Python/Node backend
- Maybe add MongoDB or Redis (multi-container)
- Dockerize the whole thing
- Push to GitHub + Docker Hub

✅ Bonus:

- Try deploying it on Render or Fly.io (both support Docker)

---

# 🧪 CHALLENGE

> 💼 **Internship Readiness Challenge**

Make a containerized project with:

- One backend (Node.js or Python)
- Dockerfile & .dockerignore
- Instructions in README
- Pushed to GitHub
- Bonus: Include `docker-compose.yml` if using DB

---

# 🏁 Wrapping Up

You Just Learned

Skill

Docker concepts

Foundational

Writing a Dockerfile

Job-ready

Running containers

Production-level

Using docker-compose

Team-level collaboration

Publishing on DockerHub

Portfolio-ready

---

👨‍🏫 **Final Tip from Your Professor**

> You don’t need 20 projects.  
> You need **one good containerized app**, clean Git history, proper docs, and you **own the interview**.

Ready to containerize your future? Let's do it.

Want me to review your Dockerfile or project? Drop the GitHub repo here.
