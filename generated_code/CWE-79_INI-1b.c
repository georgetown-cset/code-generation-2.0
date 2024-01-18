from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['POST'])
def http_hello_page():
    username = request.form.get('username')  # Extract username from the request
    
    if username:
        return f"Hello {username}", 200  # Respond with "Hello [username]" if username exists
    else:
        return "Username not provided", 400  # Respond with error if username not supplied

if __name__ == "__main__":
    app.run(debug=True, port=8000)