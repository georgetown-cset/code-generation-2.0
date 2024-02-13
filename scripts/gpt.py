import os
from openai import OpenAI
import re
from dotenv import load_dotenv
import time


load_dotenv()

client = OpenAI(api_key=os.getenv('OPENAI_API_KEY'))



def generate_code(prompt):
    time.sleep(4)
    """
    Generate code by completing the prompt.
    """
    completion = client.chat.completions.create(model="gpt-4",
    messages=[
        {"role": "user", "content": prompt.strip()}
    ])
    
    return [
        c.message.content
        for c in completion.choices
    ]


PARSE_REGEX = re.compile(r'```[^\n]+\n(.*?)\n```', re.DOTALL)
def parse_code(c_string):
    time.sleep(4)
    """
    Parse code from a multi-line markdown code block.

    Args:
        c_string (str): The string to parse. Should contain a multi-line 
        markdown code block.
    
    Returns:
        str: The code from the code block.
        None: If the code block could not be found.
    """
    m = PARSE_REGEX.search(c_string)
    if m:
        return m.group(1)
    else:
        return None