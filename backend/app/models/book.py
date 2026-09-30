from sqlalchemy import Column, Integer, String, Numeric

from app.database import Base


class Book(Base):
    __tablename__ = "books"

    book_id = Column(Integer, primary_key=True)
    title = Column(String(200), nullable=False)
    author = Column(String(150), nullable=False)
    price = Column(Numeric(10, 2), nullable=False)
