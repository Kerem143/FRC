from flask import Flask, render_template, request, jsonify
import os
import subprocess

app = Flask(__name__)

C_KODLARI_DIR = '/app/c_kodlari'

@app.route('/')
def index():
    if os.path.exists(C_KODLARI_DIR):
        files = [f for f in os.listdir(C_KODLARI_DIR) if f.endswith('.cpp')]
    else:
        files = []
    return render_template('index.html', files=files)

@app.route('/calistir', methods=['POST'])
def calistir():
    dosya_adi = request.json.get('dosya_adi')
    dosya_yolu = os.path.join(C_KODLARI_DIR, dosya_adi)
    
    if not os.path.exists(dosya_yolu):
        return jsonify({'error': 'Dosya bulunamadi!'})
    
    output_exe = os.path.join(C_KODLARI_DIR, 'temp_program')
    
    derleme = subprocess.run(['g++', dosya_yolu, '-o', output_exe], capture_output=True, text=True)
    if derleme.returncode != 0:
        return jsonify({'output': f"Derleme Hatasi:\n{derleme.stderr}"})
    
    calisma = subprocess.run([output_exe], capture_output=True, text=True)
    
    if os.path.exists(output_exe):
        os.remove(output_exe)
        
    return jsonify({'output': calisma.stdout if calisma.stdout else calisma.stderr})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
