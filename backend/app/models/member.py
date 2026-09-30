from sqlalchemy import Column, Integer, String

from app.database import Base


class Member(Base):
    __tablename__ = "members"

    member_id = Column(Integer, primary_key=True)
    name = Column(String(100), nullable=False)
    email = Column(String(150), nullable=False)
    phone_num = Column(String(20), nullable=False)
