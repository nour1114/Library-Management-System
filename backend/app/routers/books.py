from fastapi import APIRouter, Depends
from sqlalchemy.orm import Session

from app.database import SessionLocal
from app.models.book import Book


router = APIRouter(
    prefix="/books",
    tags=["Books"]
)


def get_db():
    db = SessionLocal()

    try:
        yield db

    finally:
        db.close()


#  CREATE BOOK 

@router.post("/")
def create_book(
    book_id: int,
    title: str,
    author: str,
    price: float,
    db: Session = Depends(get_db)
):
    new_book = Book(
        book_id=book_id,
        title=title,
        author=author,
        price=price
    )

    db.add(new_book)
    db.commit()
    db.refresh(new_book)

    return {
        "message": "Book added successfully",
        "book_id": new_book.book_id,
        "title": new_book.title,
        "author": new_book.author,
        "price": float(new_book.price)
    }


# GET ALL BOOKS 

@router.get("/")
def get_books(db: Session = Depends(get_db)):
    books = db.query(Book).all()

    return books