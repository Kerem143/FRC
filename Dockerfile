FROM python:3.10-slim
RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*
WORKDIR /app
RUN pip install flask
CMD ["python", "main.py"]
