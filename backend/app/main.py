from fastapi import FastAPI


app = FastAPI(
    title="Library Management System API",
    description="Backend API for the Library Management System",
    version="1.0.0"
)


@app.get("/")
def root():
    return {
        "message": "Library Management System API is running"
    }