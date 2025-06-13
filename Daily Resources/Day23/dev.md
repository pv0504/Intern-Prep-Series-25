# Neural Network Basics - 1-Day Crash Course

## 🎯 Today's Learning Goal
By the end of today, you'll understand neural network fundamentals and build your first working neural network from scratch!

## 📚 Essential Concepts to Learn Today

### Core Building Blocks (1.5 hours)
- **What is a Neural Network?** - Biological inspiration and basic structure
- **Neurons/Perceptrons** - The basic computational unit
- **Weights and Biases** - How networks store learned information
- **Activation Functions** - Sigmoid, ReLU (focus on these two only)
- **Network Architecture** - Input layer, hidden layers, output layer

### Learning Process (1.5 hours)
- **Forward Propagation** - How data flows through the network
- **Loss Functions** - Mean Squared Error and Cross-entropy (basics only)
- **Backpropagation** - How networks learn (intuition, not deep math)
- **Gradient Descent** - The optimization algorithm

### Key Math You Need (1 hour)
- **Dot Product** - Essential for forward propagation
- **Chain Rule** - Foundation of backpropagation
- **Matrix Multiplication** - How layers communicate
- **Derivatives** - Basic understanding for optimization

## 📖 Quick Learning Resources

### Must-Watch Videos (2-3 hours total)
- **3Blue1Brown Neural Networks Playlist** - https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi
  - Watch episodes 1-3 (about 45 minutes total)
- **StatQuest Neural Networks** - Simple explanations (30 minutes)

### Quick References
- **CS229 Lecture Notes** - Skim the neural network section for math details
- **TensorFlow Playground** - Interactive visualization tool
- **Keras Documentation** - For framework syntax later

### Books for Quick Reference
- **"Neural Networks and Deep Learning" by Michael Nielsen** - Online, beginner-friendly
- **"Hands-On Machine Learning" Chapter 10** - Practical implementation

## 🛠️ Today's Hands-On Tasks

### Task 1: Build a Perceptron from Scratch (2 hours)
**Goal**: Understand the basic building block of neural networks

**Implementation**:
```python
import numpy as np
import matplotlib.pyplot as plt

class Perceptron:
    def __init__(self, learning_rate=0.1, n_iterations=100):
        self.learning_rate = learning_rate
        self.n_iterations = n_iterations
    
    def fit(self, X, y):
        # Initialize weights and bias
        self.weights = np.zeros(X.shape[1])
        self.bias = 0
        
        # Training loop
        for _ in range(self.n_iterations):
            for i in range(X.shape[0]):
                # Forward pass
                linear_output = np.dot(X[i], self.weights) + self.bias
                prediction = 1 if linear_output >= 0 else 0
                
                # Update if wrong
                if prediction != y[i]:
                    self.weights += self.learning_rate * (y[i] - prediction) * X[i]
                    self.bias += self.learning_rate * (y[i] - prediction)
    
    def predict(self, X):
        linear_output = np.dot(X, self.weights) + self.bias
        return np.where(linear_output >= 0, 1, 0)

# Quick test
X = np.array([[0,0], [0,1], [1,0], [1,1]])
y_and = np.array([0, 0, 0, 1])  # AND gate

perceptron = Perceptron()
perceptron.fit(X, y_and)
print("AND gate predictions:", perceptron.predict(X))
```

**Your tasks**:
1. Copy and run the code above
2. Test with OR gate: `y_or = [0, 1, 1, 1]`
3. Try XOR gate: `y_xor = [0, 1, 1, 0]` (will fail - understand why!)
4. Visualize the decision boundary

### Task 2: MNIST Neural Network (2 hours)
**Goal**: Build a multi-layer network for digit classification

**Quick Implementation using Keras**:
```python
import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt

# Load data
(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

# Preprocess
x_train = x_train.reshape(60000, 784) / 255.0
x_test = x_test.reshape(10000, 784) / 255.0
y_train = keras.utils.to_categorical(y_train, 10)
y_test = keras.utils.to_categorical(y_test, 10)

# Build model
model = keras.Sequential([
    keras.layers.Dense(128, activation='relu', input_shape=(784,)),
    keras.layers.Dense(64, activation='relu'),
    keras.layers.Dense(10, activation='softmax')
])

# Compile
model.compile(optimizer='adam',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

# Train
history = model.fit(x_train, y_train, 
                    epochs=10, 
                    batch_size=32,
                    validation_split=0.1,
                    verbose=1)

# Test
test_loss, test_accuracy = model.evaluate(x_test, y_test, verbose=0)
print(f"Test accuracy: {test_accuracy:.4f}")

# Visualize some predictions
predictions = model.predict(x_test[:5])
for i in range(5):
    plt.subplot(1, 5, i+1)
    plt.imshow(x_test[i].reshape(28, 28), cmap='gray')
    plt.title(f"Pred: {np.argmax(predictions[i])}")
    plt.axis('off')
plt.show()
```

**Your tasks**:
1. Run the code and achieve >95% accuracy
2. Experiment with different architectures
3. Try different optimizers (sgd, rmsprop)
4. Visualize training curves

## 💡 Today's Key Takeaways

### What You'll Understand
- **How neural networks work** - Forward pass, backpropagation, training
- **When to use them** - Pattern recognition, classification, regression
- **Basic architectures** - Feedforward networks, layer sizes
- **Training process** - Loss, optimization, epochs, batches

### What You'll Be Able to Do
- **Build simple networks** - Using both scratch implementation and Keras
- **Train on real data** - MNIST digit classification
- **Debug common issues** - Overfitting, underfitting, poor accuracy
- **Experiment with hyperparameters** - Learning rate, architecture, epochs

## 🚀 Next Steps After Today

### Immediate (Next Week)
- **Try different datasets** - CIFAR-10 for images, IMDB for text
- **Learn CNNs** - For better image classification
- **Experiment with regularization** - Dropout, batch normalization

### Short Term (Next Month)
- **Deep dive into one area** - Computer Vision or NLP
- **Learn advanced architectures** - ResNet, LSTM, Transformers
- **Join Kaggle competitions** - Apply skills to real problems

### Frameworks to Explore
- **TensorFlow/Keras** - Industry standard, great for beginners
- **PyTorch** - More flexible, preferred for research
- **Scikit-learn** - Good for traditional ML and simple networks

## 🎯 Success Metrics for Today

By the end of today, you should be able to:
- [ ] Explain what a neural network is and how it learns
- [ ] Implement a perceptron from scratch
- [ ] Build and train a neural network using Keras
- [ ] Achieve >95% accuracy on MNIST
- [ ] Understand why XOR can't be solved with a single perceptron
- [ ] Know the difference between training and testing
- [ ] Identify overfitting vs underfitting

## ⚡ Quick Tips for Today

### Learning Efficiency
- **Focus on intuition first** - Don't get bogged down in complex math
- **Code along** - Type out examples, don't just read
- **Experiment freely** - Change parameters and see what happens
- **Ask "why"** - Understand the reasoning behind each step

### Common Beginner Pitfalls
- **Don't skip the basics** - Understand perceptrons before deep networks
- **Normalize your data** - Always scale inputs to 0-1 range
- **Use appropriate loss functions** - MSE for regression, crossentropy for classification
- **Monitor training** - Watch for overfitting with validation curves

### Setting Up Your Environment
```bash
# Install required packages
pip install tensorflow numpy matplotlib scikit-learn

# Or use Google Colab for free GPU access
# Just go to colab.research.google.com
```

Remember: Today is about building intuition and getting hands-on experience. Don't worry about understanding every mathematical detail - focus on getting neural networks working and understanding the big picture!
