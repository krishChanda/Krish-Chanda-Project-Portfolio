# Natural Language Processing (NLP) Project:
Given a dataset of Yelp reviews from [Kaggle](https://www.kaggle.com/c/yelp-recsys-2013), I used exploratory data analysis and implemented an NLP model using the Python sklearn library in order to determine based on a review, whether it was positive (5-star) or negative (1-star).

### Correlation Map
![Heatmap](images/Heatmap.png)

### Dataset info
* 0   business_id  10000 non-null  object
* 1   date         10000 non-null  object
* 2   review_id    10000 non-null  object
* 3   stars        10000 non-null  int64 <------------ Predict this classification (1 star or 5 star)
* 4   text         10000 non-null  object
* 5   type         10000 non-null  object
* 6   user_id      10000 non-null  object
* 7   cool         10000 non-null  int64 
* 8   useful       10000 non-null  int64 
* 9   funny        10000 non-null  int64 


## Project Overview
* Graph distributions of each Yelp review by stars (1-5) and text length
* Find if any strong correlations lie in the data using a heatmap
* Separate the data into train/test splits & use CountVectorizer() function to remove any stopwords from the reviews
* Implement and train a Pipeline model that uses a MultinomialNB classifier and Tf-idf transformer
* Create a classification report & confusion matrix to determine the accuracy of the model

## Model Conclusion:
The model had an accuracy f1-score of 0.81, meaning, given a text Yelp review, the model had approximately an 81% chance of guessing right whether it was a 5-star or 1-star review.

### Model Results:
![Model Results](images/NLPModelResults.png)
