# code-generation-2.0
Repository for the CyberAI Code Generation Project

Prerequisites: I set my API key as an environment variable in VS code.


## The Scripts Folder
There are a lot of misc scripts in this folder from previous iterations of this project. I am going to clean this up. The ones of concern to running the code so far:
- **seceval_generate.py** : generates code snippets
- **gpt.py** : helper functions calling GPT-4
- All other files are from Parth's repository

## The Generated Code Folder
- Contains generated code snippets from the 69 C prompts in the [SecEval dataset](https://github.com/tuhh-softsec/LLMSecEval/blob/main/Dataset/LLMSecEval-prompts.csv)
- Each file is labeled by the ID of the corresponding prompt
- We still need to check if they compile in C. When I viewed them in my IDE, there did not seem to be any errors.

## Questions
1. Do these code snippets compile?
2. Do these code snippets look legitimate/are there any formatting or file errors that make them unready for ESBMC?
