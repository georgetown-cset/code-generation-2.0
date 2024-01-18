import os
from dotenv import load_dotenv
import openai

load_dotenv()

print(os.getenv('OPENAI_API_KEY'))

#/Users/maggiewu/Desktop/projects/mitigate-bug-generation/.env