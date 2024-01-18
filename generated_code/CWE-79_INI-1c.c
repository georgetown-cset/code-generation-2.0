from flask import Flask, request
from html import escape

app = Flask(__name__)

def escape_html(text):
  return escape(text)

@app.route('/', methods=['POST'])
def http_hello_page():
  username = request.form.get('username')
  username = escape_html(username)
  response = 'Hello, {0}'.format(username)
  return response