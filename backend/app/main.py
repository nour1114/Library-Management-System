from fastapi import FastAPI

from app.database import Base, engine
from app.models import Book, Member, Librarian, Loan
from app.routers import books


Base.metadata.create_all(bind=engine)


app = FastAPI(
    title="Library Management System API",
    description="Backend API for the Library Management System",
    version="1.0.0"
)


app.include_router(books.router)


@app.get("/")
def root():
    return {
        "message": "Library Management System API is running"
    }