# Feature Engineering Basics - Complete Learning Guide

## 🎯 What is Feature Engineering?

Feature engineering is the process of selecting, transforming, and creating features (input variables) from raw data to improve machine learning model performance. It's often considered the most important step in the ML pipeline - good features can make a simple model outperform a complex one with poor features.

## 📚 Essential Concepts to Learn

### Data Types and Their Transformations
- **Numerical Features**: Continuous and discrete values
- **Categorical Features**: Nominal and ordinal categories
- **Text Features**: Unstructured text data
- **DateTime Features**: Time-based information
- **Image Features**: Pixel data and extracted features
- **Geospatial Features**: Location-based data

### Feature Creation Techniques
- **Domain Knowledge Features**: Business logic-based features
- **Interaction Features**: Combinations of existing features
- **Polynomial Features**: Higher-order relationships
- **Binning/Discretization**: Converting continuous to categorical
- **Aggregation Features**: Group-based statistics
- **Time-based Features**: Temporal patterns and trends

### Feature Selection Methods
- **Filter Methods**: Statistical tests (correlation, chi-square, mutual information)
- **Wrapper Methods**: Forward/backward selection, recursive feature elimination
- **Embedded Methods**: L1/L2 regularization, tree-based importance
- **Dimensionality Reduction**: PCA, t-SNE, UMAP

### Data Preprocessing
- **Handling Missing Values**: Imputation strategies
- **Outlier Detection**: Statistical and model-based approaches
- **Normalization/Standardization**: Scaling techniques
- **Encoding Categorical Variables**: One-hot, label, target encoding
- **Feature Scaling**: Min-max, standard, robust scaling

## 📖 Learning Resources

### Free Online Courses
- **Feature Engineering for Machine Learning** (Coursera) - Comprehensive coverage
- **Kaggle Learn: Feature Engineering** - Practical, hands-on approach
- **Fast.ai Practical Deep Learning** - Real-world feature engineering
- **CS229 by Anand Avati** (Stanford) - Mathematical foundations
- **Applied Machine Learning** (Andrew Ng) - Feature engineering in context

### Books
- **"Feature Engineering for Machine Learning" by Alice Zheng & Amanda Casari** - Comprehensive guide
- **"Hands-On Machine Learning" by Aurélien Géron** - Practical implementation
- **"Python Feature Engineering Cookbook" by Soledad Galli** - Recipe-based approach
- **"Feature Engineering and Selection" by Kuhn & Johnson** - Statistical perspective

### Interactive Platforms
- **Kaggle Competitions** - Real-world feature engineering challenges
- **Google Colab** - Free environment for experimentation
- **Jupyter Notebooks** - Interactive development
- **Papers With Code** - Latest research in feature engineering

### Documentation and References
- **Scikit-learn Feature Engineering** - Official documentation and examples
- **Pandas Documentation** - Data manipulation techniques
- **Feature-engine Library** - Specialized feature engineering tools
- **Category Encoders** - Advanced categorical encoding methods

### YouTube Channels and Videos
- **Krish Naik** - Feature engineering tutorials
- **StatQuest** - Statistical concepts for feature selection
- **Sentdex** - Python-based feature engineering
- **Machine Learning Mastery** - Practical techniques
- **Kaggle YouTube** - Competition winner insights

## 🛠️ Hands-On Tasks

### Task 1: Numerical Feature Engineering
**Goal**: Master techniques for handling numerical data

**Dataset**: House prices or any regression dataset

```python
import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler, MinMaxScaler, RobustScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
import seaborn as sns

# Load sample data
# You can use Boston Housing, House Prices, or create synthetic data
np.random.seed(42)
n_samples = 1000
data = {
    'price': np.random.normal(300000, 100000, n_samples),
    'size_sqft': np.random.normal(2000, 500, n_samples),
    'bedrooms': np.random.poisson(3, n_samples),
    'age_years': np.random.exponential(10, n_samples),
    'income': np.random.lognormal(11, 0.5, n_samples)
}
df = pd.DataFrame(data)

# Add some missing values and outliers
df.loc[np.random.choice(df.index, 50), 'income'] = np.nan
df.loc[np.random.choice(df.index, 20), 'size_sqft'] = df['size_sqft'] * 3  # outliers

print("Original data shape:", df.shape)
print("\nData info:")
print(df.info())
print("\nBasic statistics:")
print(df.describe())
```

**Feature Engineering Tasks**:

1. **Handle Missing Values**:
```python
# Different imputation strategies
from sklearn.impute import SimpleImputer, KNNImputer

# Mean imputation
df['income_mean_imputed'] = SimpleImputer(strategy='mean').fit_transform(df[['income']])

# Median imputation
df['income_median_imputed'] = SimpleImputer(strategy='median').fit_transform(df[['income']])

# KNN imputation
df['income_knn_imputed'] = KNNImputer(n_neighbors=5).fit_transform(df[['income']])[:, 0]
```

2. **Create New Features**:
```python
# Log transformation for skewed data
df['log_price'] = np.log1p(df['price'])
df['log_income'] = np.log1p(df['income_mean_imputed'])

# Square root transformation
df['sqrt_size'] = np.sqrt(df['size_sqft'])

# Interaction features
df['price_per_sqft'] = df['price'] / df['size_sqft']
df['size_bedroom_ratio'] = df['size_sqft'] / (df['bedrooms'] + 1)

# Binning continuous variables
df['age_group'] = pd.cut(df['age_years'], bins=[0, 5, 15, 30, 100], 
                        labels=['new', 'recent', 'old', 'very_old'])

# Polynomial features
df['size_squared'] = df['size_sqft'] ** 2
df['income_size_interaction'] = df['income_mean_imputed'] * df['size_sqft']
```

3. **Handle Outliers**:
```python
# Detect outliers using IQR
def detect_outliers_iqr(df, column):
    Q1 = df[column].quantile(0.25)
    Q3 = df[column].quantile(0.75)
    IQR = Q3 - Q1
    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR
    return (df[column] < lower_bound) | (df[column] > upper_bound)

# Mark outliers
df['size_outlier'] = detect_outliers_iqr(df, 'size_sqft')

# Cap outliers
df['size_capped'] = df['size_sqft'].clip(
    lower=df['size_sqft'].quantile(0.05),
    upper=df['size_sqft'].quantile(0.95)
)
```

4. **Feature Scaling**:
```python
# Different scaling methods
scaler_standard = StandardScaler()
scaler_minmax = MinMaxScaler()
scaler_robust = RobustScaler()

numerical_features = ['size_sqft', 'income_mean_imputed', 'age_years']

df['size_standard'] = scaler_standard.fit_transform(df[['size_sqft']])
df['size_minmax'] = scaler_minmax.fit_transform(df[['size_sqft']])
df['size_robust'] = scaler_robust.fit_transform(df[['size_sqft']])
```

### Task 2: Categorical Feature Engineering
**Goal**: Master categorical variable handling and encoding

```python
# Create sample categorical data
np.random.seed(42)
n_samples = 1000

categorical_data = {
    'city': np.random.choice(['NYC', 'LA', 'Chicago', 'Houston', 'Phoenix'], n_samples),
    'property_type': np.random.choice(['House', 'Condo', 'Townhouse'], n_samples),
    'grade': np.random.choice(['A', 'B', 'C', 'D'], n_samples, p=[0.1, 0.3, 0.4, 0.2]),
    'neighborhood_quality': np.random.choice(['Excellent', 'Good', 'Average', 'Poor'], 
                                           n_samples, p=[0.15, 0.35, 0.35, 0.15]),
    'target': np.random.normal(100, 20, n_samples)
}

cat_df = pd.DataFrame(categorical_data)
print("Categorical data shape:", cat_df.shape)
print("\nValue counts for each category:")
for col in cat_df.select_dtypes(include=['object']).columns:
    print(f"\n{col}:")
    print(cat_df[col].value_counts())
```

**Encoding Tasks**:

1. **One-Hot Encoding**:
```python
from sklearn.preprocessing import OneHotEncoder
import pandas as pd

# One-hot encoding
one_hot_encoder = OneHotEncoder(sparse=False, drop='first')
city_encoded = one_hot_encoder.fit_transform(cat_df[['city']])
city_columns = [f'city_{cat}' for cat in one_hot_encoder.categories_[0][1:]]

# Add to dataframe
for i, col in enumerate(city_columns):
    cat_df[col] = city_encoded[:, i]

# Or use pandas get_dummies
property_dummies = pd.get_dummies(cat_df['property_type'], prefix='property', drop_first=True)
cat_df = pd.concat([cat_df, property_dummies], axis=1)
```

2. **Label Encoding**:
```python
from sklearn.preprocessing import LabelEncoder

# Label encoding for ordinal features
quality_mapping = {'Poor': 1, 'Average': 2, 'Good': 3, 'Excellent': 4}
cat_df['neighborhood_quality_encoded'] = cat_df['neighborhood_quality'].map(quality_mapping)

# Grade encoding
grade_mapping = {'D': 1, 'C': 2, 'B': 3, 'A': 4}
cat_df['grade_encoded'] = cat_df['grade'].map(grade_mapping)
```

3. **Target Encoding**:
```python
# Target encoding (mean encoding)
def target_encode(df, categorical_col, target_col, alpha=5):
    # Global mean
    global_mean = df[target_col].mean()
    
    # Category means and counts
    category_stats = df.groupby(categorical_col)[target_col].agg(['mean', 'count'])
    
    # Smoothed target encoding
    smoothed_means = (category_stats['mean'] * category_stats['count'] + 
                     global_mean * alpha) / (category_stats['count'] + alpha)
    
    return df[categorical_col].map(smoothed_means)

cat_df['city_target_encoded'] = target_encode(cat_df, 'city', 'target')
```

4. **Frequency Encoding**:
```python
# Frequency encoding
city_freq = cat_df['city'].value_counts().to_dict()
cat_df['city_frequency'] = cat_df['city'].map(city_freq)
```

### Task 3: Text Feature Engineering
**Goal**: Extract features from text data

```python
import re
from sklearn.feature_extraction.text import TfidfVectorizer, CountVectorizer
from sklearn.preprocessing import LabelEncoder
import nltk
from collections import Counter

# Sample text data
text_data = [
    "Great house with beautiful garden and modern kitchen",
    "Spacious apartment near downtown with parking",
    "Cozy home perfect for families with children",
    "Luxury condo with amazing city views and amenities",
    "Affordable starter home needs some renovation work",
    "Beautiful property with large backyard and pool",
    "Modern townhouse in quiet neighborhood",
    "Charming house with hardwood floors throughout"
]

text_df = pd.DataFrame({
    'description': text_data,
    'price': [450000, 380000, 320000, 650000, 250000, 520000, 410000, 365000]
})
```

**Text Feature Engineering Tasks**:

1. **Basic Text Features**:
```python
# Text length features
text_df['description_length'] = text_df['description'].str.len()
text_df['word_count'] = text_df['description'].str.split().str.len()
text_df['avg_word_length'] = text_df['description_length'] / text_df['word_count']
text_df['sentence_count'] = text_df['description'].str.count('\.') + 1

# Character-based features
text_df['uppercase_count'] = text_df['description'].str.count(r'[A-Z]')
text_df['digit_count'] = text_df['description'].str.count(r'\d')
text_df['special_char_count'] = text_df['description'].str.count(r'[^A-Za-z0-9\s]')
```

2. **Keyword Features**:
```python
# Define important keywords
luxury_keywords = ['luxury', 'amazing', 'beautiful', 'modern', 'spacious']
negative_keywords = ['needs', 'renovation', 'work', 'affordable', 'starter']

# Create keyword features
text_df['luxury_keyword_count'] = text_df['description'].str.lower().apply(
    lambda x: sum(1 for keyword in luxury_keywords if keyword in x)
)

text_df['negative_keyword_count'] = text_df['description'].str.lower().apply(
    lambda x: sum(1 for keyword in negative_keywords if keyword in x)
)

# Specific feature presence
text_df['has_garden'] = text_df['description'].str.contains('garden', case=False).astype(int)
text_df['has_parking'] = text_df['description'].str.contains('parking', case=False).astype(int)
text_df['has_pool'] = text_df['description'].str.contains('pool', case=False).astype(int)
```

3. **TF-IDF Features**:
```python
# TF-IDF vectorization
tfidf = TfidfVectorizer(max_features=20, stop_words='english', lowercase=True)
tfidf_features = tfidf.fit_transform(text_df['description'])

# Convert to dataframe
tfidf_df = pd.DataFrame(tfidf_features.toarray(), 
                       columns=[f'tfidf_{word}' for word in tfidf.get_feature_names_out()])
text_df = pd.concat([text_df, tfidf_df], axis=1)
```

### Task 4: DateTime Feature Engineering
**Goal**: Extract temporal patterns and trends

```python
# Create sample datetime data
import datetime as dt

np.random.seed(42)
start_date = dt.datetime(2020, 1, 1)
end_date = dt.datetime(2023, 12, 31)

# Generate random dates
date_range = pd.date_range(start=start_date, end=end_date, freq='D')
sample_dates = np.random.choice(date_range, size=1000)

datetime_df = pd.DataFrame({
    'transaction_date': sample_dates,
    'amount': np.random.normal(1000, 300, 1000)
})

# Ensure datetime type
datetime_df['transaction_date'] = pd.to_datetime(datetime_df['transaction_date'])
```

**DateTime Feature Engineering Tasks**:

1. **Basic Temporal Features**:
```python
# Extract basic datetime components
datetime_df['year'] = datetime_df['transaction_date'].dt.year
datetime_df['month'] = datetime_df['transaction_date'].dt.month
datetime_df['day'] = datetime_df['transaction_date'].dt.day
datetime_df['day_of_week'] = datetime_df['transaction_date'].dt.dayofweek
datetime_df['day_of_year'] = datetime_df['transaction_date'].dt.dayofyear
datetime_df['week_of_year'] = datetime_df['transaction_date'].dt.isocalendar().week
datetime_df['quarter'] = datetime_df['transaction_date'].dt.quarter

# Weekend indicator
datetime_df['is_weekend'] = (datetime_df['day_of_week'] >= 5).astype(int)

# Month names for better interpretation
datetime_df['month_name'] = datetime_df['transaction_date'].dt.strftime('%B')
datetime_df['weekday_name'] = datetime_df['transaction_date'].dt.strftime('%A')
```

2. **Cyclical Features**:
```python
# Cyclical encoding for periodic features
datetime_df['month_sin'] = np.sin(2 * np.pi * datetime_df['month'] / 12)
datetime_df['month_cos'] = np.cos(2 * np.pi * datetime_df['month'] / 12)

datetime_df['day_of_week_sin'] = np.sin(2 * np.pi * datetime_df['day_of_week'] / 7)
datetime_df['day_of_week_cos'] = np.cos(2 * np.pi * datetime_df['day_of_week'] / 7)

datetime_df['day_of_year_sin'] = np.sin(2 * np.pi * datetime_df['day_of_year'] / 365)
datetime_df['day_of_year_cos'] = np.cos(2 * np.pi * datetime_df['day_of_year'] / 365)
```

3. **Time-based Aggregations**:
```python
# Sort by date for time-based features
datetime_df = datetime_df.sort_values('transaction_date')

# Rolling statistics
datetime_df['amount_7day_mean'] = datetime_df['amount'].rolling(window=7, min_periods=1).mean()
datetime_df['amount_30day_mean'] = datetime_df['amount'].rolling(window=30, min_periods=1).mean()
datetime_df['amount_7day_std'] = datetime_df['amount'].rolling(window=7, min_periods=1).std()

# Lag features
datetime_df['amount_lag_1'] = datetime_df['amount'].shift(1)
datetime_df['amount_lag_7'] = datetime_df['amount'].shift(7)

# Time since features
reference_date = datetime_df['transaction_date'].min()
datetime_df['days_since_start'] = (datetime_df['transaction_date'] - reference_date).dt.days
```

### Task 5: Feature Selection and Evaluation
**Goal**: Select the most important features for your model

```python
from sklearn.feature_selection import SelectKBest, f_regression, mutual_info_regression
from sklearn.feature_selection import RFE
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# Create a comprehensive dataset for feature selection
np.random.seed(42)
n_samples = 1000

# Generate mixed feature types
feature_data = pd.DataFrame({
    'numerical_1': np.random.normal(0, 1, n_samples),
    'numerical_2': np.random.normal(0, 1, n_samples),
    'numerical_3': np.random.normal(0, 1, n_samples),
    'categorical_1': np.random.choice(['A', 'B', 'C'], n_samples),
    'categorical_2': np.random.choice(['X', 'Y'], n_samples),
    'noise_1': np.random.normal(0, 1, n_samples),  # irrelevant
    'noise_2': np.random.normal(0, 1, n_samples),  # irrelevant
})

# Create target with known relationships
feature_data['target'] = (2 * feature_data['numerical_1'] + 
                         1.5 * feature_data['numerical_2'] +
                         np.where(feature_data['categorical_1'] == 'A', 3, 0) +
                         np.random.normal(0, 0.5, n_samples))

# Encode categorical variables
feature_data = pd.get_dummies(feature_data, columns=['categorical_1', 'categorical_2'])
```

**Feature Selection Tasks**:

1. **Correlation Analysis**:
```python
# Correlation matrix
correlation_matrix = feature_data.corr()

# Plot correlation heatmap
plt.figure(figsize=(12, 10))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', center=0)
plt.title('Feature Correlation Matrix')
plt.show()

# Find highly correlated features
def find_correlated_features(df, threshold=0.8):
    corr_matrix = df.corr().abs()
    upper_triangle = corr_matrix.where(
        np.triu(np.ones(corr_matrix.shape), k=1).astype(bool)
    )
    
    high_corr_pairs = []
    for column in upper_triangle.columns:
        correlated_features = upper_triangle.index[upper_triangle[column] > threshold].tolist()
        if correlated_features:
            for feature in correlated_features:
                high_corr_pairs.append((column, feature, upper_triangle.loc[feature, column]))
    
    return high_corr_pairs

high_corr = find_correlated_features(feature_data)
print("Highly correlated feature pairs:")
for pair in high_corr:
    print(f"{pair[0]} - {pair[1]}: {pair[2]:.3f}")
```

2. **Statistical Feature Selection**:
```python
# Separate features and target
X = feature_data.drop('target', axis=1)
y = feature_data['target']

# Univariate feature selection
k_best = SelectKBest(score_func=f_regression, k=5)
X_k_best = k_best.fit_transform(X, y)

# Get selected feature names
selected_features = X.columns[k_best.get_support()]
print("Top 5 features selected by univariate test:")
print(selected_features.tolist())

# Feature scores
feature_scores = pd.DataFrame({
    'feature': X.columns,
    'score': k_best.scores_
}).sort_values('score', ascending=False)

print("\nAll feature scores:")
print(feature_scores)
```

3. **Model-based Feature Selection**:
```python
# Random Forest feature importance
rf = RandomForestRegressor(n_estimators=100, random_state=42)
rf.fit(X, y)

# Get feature importance
feature_importance = pd.DataFrame({
    'feature': X.columns,
    'importance': rf.feature_importances_
}).sort_values('importance', ascending=False)

print("Random Forest Feature Importance:")
print(feature_importance)

# Plot feature importance
plt.figure(figsize=(10, 6))
sns.barplot(data=feature_importance.head(10), x='importance', y='feature')
plt.title('Top 10 Most Important Features')
plt.xlabel('Feature Importance')
plt.show()
```

4. **Recursive Feature Elimination**:
```python
# RFE with linear regression
lr = LinearRegression()
rfe = RFE(estimator=lr, n_features_to_select=5)
rfe.fit(X, y)

# Selected features
rfe_selected = X.columns[rfe.support_]
print("Features selected by RFE:")
print(rfe_selected.tolist())

# Feature ranking
rfe_ranking = pd.DataFrame({
    'feature': X.columns,
    'ranking': rfe.ranking_
}).sort_values('ranking')

print("\nRFE Feature Ranking:")
print(rfe_ranking)
```

## 💡 Key Principles and Best Practices

### Domain Knowledge is King
- **Understand your data** - Know what each feature represents
- **Business context matters** - Create features that make business sense
- **Subject matter expertise** - Collaborate with domain experts
- **Feature interpretability** - Prefer interpretable features when possible

### Data Quality First
- **Handle missing values** thoughtfully - understand why data is missing
- **Detect and handle outliers** - but don't always remove them
- **Validate data consistency** - check for logical inconsistencies
- **Document transformations** - keep track of all preprocessing steps

### Avoid Data Leakage
- **No future information** - don't use information not available at prediction time
- **Proper train/validation splits** - especially important for time series
- **Target leakage** - be careful with features highly correlated with target
- **Cross-validation strategy** - matches your real-world scenario

### Iterative Process
- **Start simple** - begin with basic features and gradually add complexity
- **Measure impact** - always validate that new features improve performance
- **Feature interaction** - consider how features work together
- **Regular validation** - check feature performance on new data

## 🚀 Next Steps and Advanced Topics

### Advanced Techniques to Explore
- **Automated Feature Engineering** - Tools like Featuretools, tsfresh
- **Deep Feature Synthesis** - Automated creation of complex features
- **Feature Learning** - Neural networks for automatic feature extraction
- **Ensemble Feature Selection** - Combining multiple selection methods

### Specialized Domains
- **Time Series Features** - Seasonal decomposition, spectral features
- **Image Features** - Edge detection, texture analysis, CNN features
- **Graph Features** - Network analysis, centrality measures
- **Audio Features** - MFCC, spectral features, rhythm analysis

### Tools and Libraries to Master
- **Feature-engine** - Comprehensive feature engineering library
- **Category-encoders** - Advanced categorical encoding methods
- **Optuna** - Automated hyperparameter tuning including feature selection
- **SHAP** - Feature importance and interpretation

### Real-World Applications
- **Kaggle Competitions** - Practice on diverse, real-world datasets
- **Open Source Contributions** - Contribute to feature engineering libraries
- **Industry Projects** - Apply techniques to business problems
- **Research Papers** - Stay updated with latest developments

Remember: Feature engineering is both an art and a science. While there are established techniques and best practices, the most effective features often come from deep understanding of your specific domain and creative thinking about how to represent that knowledge in your data.
