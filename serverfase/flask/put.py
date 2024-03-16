from flask import Flask, redirect, url_for, request, json
app = Flask(__name__)

@app.route('/success/<name>')
def success(name):
      with open("buffer.json", "w") as f:
         json.dump(name,f)
         return 'welcome %s' % name

@app.route('/login',methods = ['POST', 'GET'])
def login():
   if request.method == 'POST':
      user = request.form['nm']
      password = request.form['password'] 
      id = request.form['id']
      accesslevel = request.form['accesslevel']
      return redirect(url_for('success',name = user))
   else:
      user = request.args.get('nm')
      return redirect(url_for('success',name = user))

if __name__ == '__main__':
   app.run(debug = True)
   
